// #include <bits/stdc++.h>
#include <stack>
#include <deque>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
// #include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if ((int)dq.size() < 2)
        {
            dq.push_back(num);
            sort(dq.begin(), dq.end());
            if(dq.size()==2 && dq.front()==dq.back()){
                dq.pop_back();
            }
        }
        else
        {
            if (num < dq.front())
            {
                dq.push_front(num);
                dq.pop_back();
            }
            else if (num < dq.back() && num > dq.front())
            {
                dq.pop_back();
                dq.push_back(num);
            }
        }
    }
    if (!dq.empty() && dq.size() == 2)
    {
        if (dq.front() == dq.back())
        {
            cout << -1 << endl;
        }
        else
        {
            cout << dq.back() << endl;
        }
    }
    else
    {
        cout << -1 << endl;
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