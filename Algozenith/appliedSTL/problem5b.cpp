// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
#include <functional>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{

    int q;
    cin >> q;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < q; i++)
    {
        string str;
        cin >> str;
        if (str == "add")
        {
            int x;
            cin >> x;
            pq.push(x);
        }
        else if (str == "remove")
        {
            if (!pq.empty())
            {
                pq.pop();
            }
        }
        else if (str == "print")
        {
            if (!pq.empty())
            {
                cout << pq.top() << endl;
            }
            else
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
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}