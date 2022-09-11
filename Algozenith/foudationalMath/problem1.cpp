// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    int gcd = __algo_gcd(1LL*0, b);
    cout << gcd << endl;
    if (c % gcd == 0)
    {
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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