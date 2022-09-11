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

int n,k;
vector<int> vc;

bool check(int x){
    int needed=0;
    for(int i=1;i<n;i++){
        int num = (vc[i]-vc[i-1]+x-1)/x -1;
        needed+=num;
    }
    if(needed>k) return 0;
    return 1;
}

void solve(){
    cin>>n>>k;
    vc.resize(n);
    int maxd=0;
    cin>>vc[0];
    for(int i=1;i<n;i++){
        cin>>vc[i];
        maxd=max(vc[i]-vc[i-1],maxd);
    }
    if(maxd==0) throw invalid_argument("maxd is 0");
    int lo=1,hi=maxd;
    int ans=-1;
    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(check(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    cout<<ans<<endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}