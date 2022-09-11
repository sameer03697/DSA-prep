// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
// #include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    map<string, int> marksMap;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            string x;
            cin >> x;
            int y;
            cin >> y;
            marksMap[x] = y;
        }
        if (str == "erase")
        {
            string x;
            cin >> x;
            if (marksMap.count(x))
            {
                marksMap.erase(x);
            }
        }
        if (str == "print")
        {
            string x;
            cin >> x;
            if (marksMap.count(x)>0)
            {
                cout << marksMap[x] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
    // cout << flush;
}