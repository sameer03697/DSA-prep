// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <deque>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 1; i < n + 1; i++)
    {
        dq.push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout << dq.at(i) << " ";
    }
    cout << endl;
    while (next_permutation(dq.begin(), dq.end()))
    {
        for (int i = 0; i < n; i++)
        {
            cout << dq.at(i) << " ";
        }
        cout << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}