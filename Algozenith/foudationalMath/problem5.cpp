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
int md = (int)1e9 + 7;
deque<int> factorial;
int fourInv;

int fact(int n)
{
    // 1 1 2 3 4 5
    while (n+10>(int)factorial.size())
    {
        /* code */
        int size = (int)factorial.size();
        factorial.push_back((factorial.back() * size % md) % md);
    }
    return factorial[n];
}
int binary_power(int a, int b){
    int ans = 1;
    while(b){
        if(b%2){
            ans = ans * a % md;
        }
        b /= 2;
        a = (a * a) % md;
    }
    return ans;
}
int mul(int a, int b){
    return (a * b) % md;
}

void solve(){
    int n;
    cin >> n;
    int ans = mul(n, n - 1);
    ans = mul(ans, n - 2);
    ans = mul(ans, n - 3);
    // cout << ans << endl;
    ans = mul(ans, fourInv);
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    factorial.push_back(1);
    fourInv = binary_power(24, md - 2);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}