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

void solve(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int pre[n], suf[n];
    pre[0] = a[0];
    suf[n - 1] = a[n - 1];
    for (int i = 1; i < n; i++)
    {
        pre[i] = max(a[i], pre[i - 1]);
    }
    for (int i = n - 2; i >= 0;i--){
        suf[i] = max(suf[i + 1], a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(suf[i], pre[i]) - a[i];
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