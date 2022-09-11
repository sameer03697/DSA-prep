// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

void solve()
{

    deque<pair<int, int>> dq;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        dq.push_back({x, 1});
        dq.push_back({y, -1});
    }
    sort(dq.begin(), dq.end(), comp);
    int cur=0, max=0;
    for (auto i : dq)
    {
        cur += i.second;
        if(cur>max){
            max = cur;
        }
    }
    cout << max << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}