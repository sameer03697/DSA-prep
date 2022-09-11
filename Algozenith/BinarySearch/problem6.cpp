// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long int
#define float long double
#define endl '\n'
int n;
int s;

bool check(int x){
    int sd = 0;//sum of digits
    int cx = x;
    while(cx){
        if(cx%10){
            sd += cx % 10;
        }
        cx /= 10;
    }
    // cout << x << " " << sd << endl;
    if (x - sd < s)
        return 1;
    else
        return 0;
}
void solve()
{
    cin >> n;
    cin >> s;
    int lo = 1, hi = n;
    int ans = -1;
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    if(ans==-1){
        ans = 0;
    }
    // cout << ans << endl;
    cout << n - ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}