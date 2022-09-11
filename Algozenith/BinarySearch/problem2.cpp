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

bool check(int x,int k){
    return vc[x]>=k;
}
bool bcheck(int x){
    if(x==n-1) return 0;
    if(vc[x]>vc[x+1]) return 1;
    return 0;
}
void solve(){
    cin>>n;
    vc.resize(n);
    int q;
    cin>>q;
    for(int i=0;i<n;i++){
        cin>>vc[i];
    }

    // for(auto v:vc){
    //     cout<<v<<" ";
    // }
    // cout<<endl;
    //[1 2 5 3 2 1] ans = 2
    //[1] ans = -1
    //[1 2] ans =-1
    int lo=0,hi=n-1;
    int ans=-1;//default value
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(bcheck(mid)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    int br=ans;
    // cout<<br<<endl;
    for(int i=0;i<q;i++){
        int k;
        cin>>k;
        ans = -1;
        // cout<<k<<endl;

        // int print=0;
        lo=0;
        if(br!=-1) hi=br;
        else hi=n-1;
        while(lo<=hi){
            int mid = (lo+hi)/2;
            if(check(mid,k)){
                // cout<<"mid in true case:"<<mid <<endl;

                ans=mid;
                hi=mid-1;
                // break;
            }else{
                // cout<<"mid in false case:"<<mid<<endl;
                lo=mid+1;
            }
        }
        int print=0;
        // cout<<ans<<vc[ans]<<endl;
        if(ans!=-1 && k==vc[ans]) {
            cout<<ans+1<<" ";
            print=1;
        }
        if(br==-1 && print) {
            // cout<<"error in line: "<<__LINE__<<endl;
            cout<<endl;
            continue;
        }
        ans=-1;
        lo=br+1;hi=n-1;
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(check(mid,k)){
                ans=mid;
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }
        if(ans!=-1 && k==vc[ans]) {
            cout<<ans+1;
            print =1;
        }
        cout<<endl;
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