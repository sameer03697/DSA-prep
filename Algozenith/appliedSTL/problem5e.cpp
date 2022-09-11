// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <iterator>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int q;
    cin >> q;
    set<int> ss;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            int x;
            cin >> x;
            if (ss.find(x) == ss.end())
            {
                ss.insert(x);

            }
        }
        else if (s == "remove")
        {
            int x;
            cin >> x;
            auto itr = ss.find(x);
            if (itr != ss.end())
            {
                ss.erase(itr);
            }
        }
        else if (s == "find")
        {
            int x;
            cin >> x;
            auto itr = ss.begin();
            advance(itr, x);
            cout << *itr << endl;
        }
        else if (s == "findpos")
        {
            int x;
            cin >> x;
            auto itr = ss.find(x);
            if (itr != ss.end())
            {
                cout << distance(ss.begin(), itr) << endl;
            }
            else
            {
                ss.insert(x);
                auto itr = ss.find(x);
                cout << distance(ss.begin(), itr) << endl;
                ss.erase(itr);
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
}