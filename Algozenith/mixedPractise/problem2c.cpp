// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    multiset<int> ss;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ss.insert(x);
    }
    int ans = 0;
    while(ss.size()>1){
        int x, y;
        auto itr = ss.begin();
        x = *itr;
        ss.erase(itr);
        itr = ss.begin();
        y = *itr;
        ss.erase(itr);
        ans += x + y;
        ss.insert(x + y);
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