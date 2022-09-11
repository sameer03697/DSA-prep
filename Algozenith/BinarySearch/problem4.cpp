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

//input that works across all functions
int n;
int k;
vector<int>vc;

bool check(int x){
    // x = x - 1;
    int zeros = 0;
    int ans = 0;
    for (int i = 0; i < x; i++)
    {
        if(vc[i]==0)
            zeros += 1;
    }
    ans = zeros;
    for (int i = x; i < n; i++)
    {
        if(vc[i]==0)
            zeros++;
        if(vc[i-x]==0)
            zeros--;
        ans = min(ans, zeros);
    }
    if(ans<=k)
        return 1;
    else
        return 0;
}

void solve(){
    cin>>n;
    cin>>k;
    vc.resize(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }
    //1 0 1 1 0 1 1 0 0 1
    //lo=2,hi=10
    int lo=k,hi=n;
    int ans=-1;//default value
    while(lo<=hi){
        int mid=(lo+hi)/2;
        // cout << lo << " " << hi << " " << check(mid) << endl;
        if (check(mid))
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
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