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
int sum(int a, int b){
    int ans = ((a%md)+(b%md))%md;
    return ans;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> prod(n+1,0);
    vector<int> arr(n+1,0);
    for(int i=0;i<q;i++){
        int a,d,l,r;
        cin>>a>>d>>l>>r;
        int temp = a - mul(l,d);
        arr[l]=sum(arr[l],temp);
        prod[l]=sum(prod[l],d);
        if(r+1<=n){
            arr[r+1]=sum(arr[r+1],-temp);
            prod[r+1]=sum(prod[r+1],-d);
        }
    }
    for(int i=2;i<=n;i++){
        arr[i]=sum(arr[i-1],arr[i]);
        prod[i]=sum(prod[i-1],prod[i]);
    }
    for(int i=1;i<=n;i++){
        int temp=sum(arr[i],mul(i,prod[i]));
        if(temp<0)
        temp+=md;
        // arr[i]=temp;
        cout<<temp<<" ";
    }
    cout<<endl;


}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}