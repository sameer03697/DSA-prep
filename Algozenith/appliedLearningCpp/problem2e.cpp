#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve()
{
    string S;
    getline(cin, S);
    int length = S.length();
    // cout << "length   " << length << endl;
    bool A = true;
    int i, j;
    i = 0;
    j = length - 1 - i;
    while (1)
    {   while(i< length && (S[i]<='a'||S[i] >='z'))
            i++;
        while(j >0 && (S[j]<='a'||S[j] >='z'))
            j--;

        if (i<j){
            break;
        }
        
        if (S[i] == S[j])
        {
            // cout << "I have continue" << i << endl;
        
        }
        else
        {
            A = false;
            break;
        }

        i++;
        j--;
        
    }
    if (A)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    string temp;
    getline(cin, temp);
    while (_t--)
        solve();
}