import pandas as pd
import gdown
import re
import os

def sanitize_filename(name):
    return re.sub(r'[<>:"/\\|?*]', '', str(name)).replace(' ', '_')

def extract_id(url):
    if not isinstance(url, str):
        return None
    # Check for /d/ID pattern
    match = re.search(r'/d/([a-zA-Z0-9_-]+)', url)
    if match:
        return match.group(1)
    # Check for id=ID pattern
    match = re.search(r'id=([a-zA-Z0-9_-]+)', url)
    if match:
        return match.group(1)
    return None

def download_file_from_google_drive(id, destination):
    import requests
    URL = "https://docs.google.com/uc?export=download"
    session = requests.Session()

    response = session.get(URL, params = { 'id' : id }, stream = True)
    token = get_confirm_token(response)

    if token:
        params = { 'id' : id, 'confirm' : token }
        response = session.get(URL, params = params, stream = True)

    save_response_content(response, destination)    

def get_confirm_token(response):
    for key, value in response.cookies.items():
        if key.startswith('download_warning'):
            return value
    return None

def save_response_content(response, destination):
    CHUNK_SIZE = 32768
    with open(destination, "wb") as f:
        for chunk in response.iter_content(CHUNK_SIZE):
            if chunk: # filter out keep-alive new chunks
                f.write(chunk)

def download_files():
    csv_path = '/workspaces/DSA-prep/notes/spreadsheet_data.csv'
    # Read CSV, skipping first row (header 0) and using second row (header 1) as column names
    # Actually, row 0 has 'Date' and 'Topic', row 1 has 'Digital Notes'. 
    # Let's read with header=1 to get 'Digital Notes' and 'Handwritten Notes'.
    # But then 'Date' and 'Topic' columns will be unnamed.
    
    df = pd.read_csv(csv_path, header=1)
    
    # Rename columns for clarity
    df = df.rename(columns={
        df.columns[0]: 'Date',
        df.columns[1]: 'Topic',
        'Digital Notes': 'Digital_Link',
        'Handwritten Notes': 'Handwritten_Link'
    })

    output_dir = '/workspaces/DSA-prep/notes'
    
    for index, row in df.iterrows():
        date = str(row['Date']).replace('/', '-')
        topic = sanitize_filename(row['Topic'])
        
        links = [
            ('Digital', row['Digital_Link']),
            ('Handwritten', row['Handwritten_Link'])
        ]
        
        for note_type, link in links:
            file_id = extract_id(link)
            if file_id:
                output_filename = f"{date}_{topic}_{note_type}.pdf"
                output_path = os.path.join(output_dir, output_filename)
                
                if os.path.exists(output_path):
                    print(f"Skipping {output_filename}, already exists.")
                    continue
                
                print(f"Downloading {output_filename}...")
                try:
                    # Try gdown first
                    url = f'https://drive.google.com/uc?id={file_id}'
                    gdown.download(url, output_path, quiet=False, fuzzy=True)
                except Exception as e:
                    print(f"gdown failed for {output_filename}: {e}")
                    print("Trying requests fallback...")
                    try:
                        download_file_from_google_drive(file_id, output_path)
                        print(f"Successfully downloaded {output_filename} with fallback.")
                    except Exception as e2:
                         print(f"Fallback failed for {output_filename}: {e2}")

if __name__ == "__main__":
    download_files()
