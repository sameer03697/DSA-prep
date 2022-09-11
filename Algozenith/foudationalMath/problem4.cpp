// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

int md = (int)1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    int ans=1;
    if (n % 2 == 0)
    {
        ans = ((n / 2) % md * (n - 1) % md) % md;
        ans -= (n % md);
    }else{
        ans = ((n) % md * ((n - 1) / 2) % md) % md;
        ans -= (n % md);
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