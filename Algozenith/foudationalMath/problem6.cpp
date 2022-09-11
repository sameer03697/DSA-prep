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

int md = (int) 1e9 + 7;
int mul(int a, int b)
{
    return a * b % md;
}
int binary_exponent(int a,int b){
    int ans = 1;
    while(b){
        if(b%2){
            ans = ans * a % md;
        }
        b /= 2;
        a = a * a % md;
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int diagnols = mul(n, n - 1);
    diagnols = mul(diagnols, binary_exponent(2, md - 2))-n;
    if(diagnols<0){
        diagnols = diagnols % md + md;
    }
    int inter = mul(n, n - 1);
    inter = mul(inter, n - 2);
    inter = mul(inter, n - 3);
    inter = mul(inter, binary_exponent(24, md - 2));
    cout << (inter + diagnols +1)%md << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}