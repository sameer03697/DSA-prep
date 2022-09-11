// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <queue>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

int md = (int)1e9 + 7;

deque<int> dq;

int fact(int n){
    // for (int i = 0; i<dq.size();i++)   
    // {
    //     cout << dq[i] << " ";
    // }
    // cout << endl;
    while(n+5>(int)dq.size()){
        // cout << "imhere" <<n<< endl;
        int last = dq.back();
        int size = (int)dq.size();
        dq.push_back((last * size % md));
    }
    return dq[n];
}
int binary_exponent(int a, int b){
    // 2 4 --> 16
    
    int ans = 1; 
    while (b > 0)
    {
        if(b%2==1){
            ans = ans * a % md; 
        }
        b /= 2;a=(a*a)%md;
    }
    return ans%md;
}

void solve()
{
    int m, n;
    cin >> m >> n;
    int mplusnFact = fact(m + n);
    int factinv = binary_exponent(fact(m) * fact(n) % md, md - 2);
    cout << mplusnFact * factinv % md << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    dq.push_back(1);
    int _t;cin>> _t; while(_t--)
    solve();
    // cout << binary_exponent(9, 5) << endl;
}