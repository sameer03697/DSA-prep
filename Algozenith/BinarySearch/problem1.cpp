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

int n;
vector<int> vc;

bool check(int x){
    return vc[0]>vc[x];
}

void solve(){
    cin>>n;
    vc.resize(n);
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }

    int lo=0,hi=n-1;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    if(ans == -1) cout<<0<<endl;
    else cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}