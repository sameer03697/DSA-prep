// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <deque>
using namespace std;
#include <math.h>
#define int long long int
#define float long double
#define endl '\n'

void solve()
{
    int n;
    cin >> n;

    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        dq.push_back(x);
    }
    int result = 0;
    int x = 1;
    for (int j = 0; j < 32; j++)
    {
        int ans = 0;
        unordered_map<int, int> parsed;
        for (int i = 0; i < n; i++)
        {

            if (parsed.find(x - dq.at(i)) != parsed.end())
            {
                ans += parsed[x - dq.at(i)];
            }
            if (parsed.find(dq.at(i)) == parsed.end())
            {
                parsed[dq.at(i)] = 1;
            }
            else
            {
                
                parsed[dq.at(i)]++ ;
            }
        }
        result += ans;
        x *= 2;
    }
    cout << result << endl;
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