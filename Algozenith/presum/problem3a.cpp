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

int md = (int)1e9+7;
int mul(int a, int b){
    int ans = ((a%md)*(b%md))%md;
    return ans;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> vc(n+1,0);
    vector<int> mv(n+1,0);
    // cout<<"error in line: "<<__LINE__<<endl;
    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;
        vc[i]=temp;
        mv[i]=mul(i,temp);
    }
    // cout<<"error in line: "<<__LINE__<<endl;
    //take presums vc and mv
    for(int i=2;i<=n;i++){
        vc[i]=(vc[i-1]+vc[i])%md;
        mv[i]=(mv[i-1]+mv[i])%md;
    }
    // cout<<"error in line: "<<__LINE__<<endl;

    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans = mv[r]-mv[l-1];
        ans-=mul(l-1,vc[r]-vc[l-1]);
        ans%=md;
        if(ans<0)
        ans=ans+md;
        cout<<ans<<endl;
    }


}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}