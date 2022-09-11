// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int q;
    cin >> q;
    deque<int> dq;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s == "insertback")
        {
            int e;
            cin >> e;
            dq.push_back(e);
        }
        else if (s == "eraseback")
        {
            if (!dq.empty())
            {
                dq.pop_back();
            }
        }
        else if (s == "insertfront")
        {
            int e;
            cin >> e;
            dq.push_front(e);
        }
        else if (s == "erasefront")
        {
            if (!dq.empty())
            {
                dq.pop_front();
            }
        }
        else if (s == "printfront")
        {
            if (!dq.empty())
            {
                cout << dq.front() << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }
        else if (s == "printback")
        {
            if (!dq.empty())
            {
                cout << dq.back() << endl;
            }
            else
            {
                cout << 0 << endl;
            }
        }else if (s=="print"){
            int e;
            cin >> e;
            if (e< (int)dq.size()){
                cout << dq.at(e) << endl;
            }else{
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