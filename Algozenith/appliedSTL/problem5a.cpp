// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int q;
    cin >> q;
    multimap<string, int> mm;
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            string x;
            int y;
            cin >> x >> y;
            mm.insert({x, y});
        }
        else if (str == "erase")
        {
            string x;
            cin >> x;
            auto itr = mm.find(x);
            mm.erase(itr);
        }
        else if (str == "eraseall")
        {
            string x;
            cin >> x;
            mm.erase(x);
        }else if (str=="print")
        {
            string x;
            cin >> x;
            auto itr = mm.find(x);
            if(itr != mm.end()){
                cout << (*itr).second << endl;
            }else
            {
                cout << 0 << endl;
            }
        }
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}