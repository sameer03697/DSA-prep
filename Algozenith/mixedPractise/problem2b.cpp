// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    unordered_map<int, int> mm;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mm[x]++;
    }
    int ans = 0;
    for (auto it = mm.begin(); it != mm.end(); ++it)
    {
        if (it->second > it->first)
        {
            ans += it->second - it->first;
        } else if (it->first>it->second)
        {
            ans += it->second;
        }else if(it->first == it-> second){
            ans += 0;
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}