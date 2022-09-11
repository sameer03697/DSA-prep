// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <unordered_set>
using namespace std;
#include <math.h>
#include <algorithm>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    unordered_set<int> ss;
    int ans = 0;
    int l = 0;
    for (int r = 0; r < v.size(); r++)
    {
        auto itr = ss.find(v.at(r));
        if (itr == ss.end())
        {
            ss.insert(v.at(r));
        }
        else
        {
            while (ss.count(v.at(r)) > 0)
            {
                ss.erase(v.at(l));
                l++;
            }
            ss.insert(v.at(r));
        }
        ans = max(ans, r-l+1);
    }

    cout << ans << endl;
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