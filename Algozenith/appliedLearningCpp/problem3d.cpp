#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve(){

    int a[26] = {0};
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size();i++){
        char c;
        c = tolower(s[i]);
        if (c >= 'a' && c <= 'z')
        {
            int num;
            num = c - 'a';
            // cout << "value of " << c << "is" << num << endl;
            a[num] +=1;
        }
    }
    for (int i=0; i< 26;i++){
        cout << a[i];
        if (i<25){
            cout << " ";
        }
    }
    cout << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t;
    string temp;
    getline(cin, temp);
    while (_t--)
        solve();
}