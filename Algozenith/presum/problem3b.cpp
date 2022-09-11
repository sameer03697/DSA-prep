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

int md=(int)1e9+7;

int binomial_exponent(int a, int b){
    int ans=1;
    while(b){
        if(b%2){
            ans=ans*a%md;
        }
        b/=2;a=(a*a)%md;
    }
    return ans;
}
int mul(int a, int b){
    int ans = ((a%md)*(b%md))%md;
    return ans;
}

void solve(){
    int n,q,k;
    cin>>n>>q>>k;
    vector<int> powK(n+1,1);
    vector<int> arr(n+1,0);
    for (int i = 1; i <=n ; i++){
        /* code */
        powK[i]=mul(powK[i-1],k);
        int temp;
        cin>>temp;
        arr[i]=temp*powK[i];
    }
    for(int i=2; i<=n;i++){
        arr[i]=(arr[i-1]+arr[i])%md;
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin>>l>>r;
        int ans = arr[r]-arr[l-1];
        int invKL=binomial_exponent(powK[l],md-2);
        ans=mul(ans,invKL);
        if(ans<0)
            ans+=md;
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