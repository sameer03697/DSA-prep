#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

void solve()
{
    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }
        else if (isupper(s[i]))
        {
            s[i] = tolower(s[i]);
        };
    }
    cout << s << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string temp;
    int _t;
    cin >> _t;
    getline(cin, temp);
    while (_t--)
        solve();
}