// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#include <algorithm>
#define int long long
#define float long double
#define endl '\n'

bool isPrime(int n)
{
    cout << n << endl;
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
  
    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0){
        return false;
    }
  
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0){
            cout << i << " " << n << endl;
            return false;
        }

    return true;
}
void solve(){
    int n;
    cin >> n;
    int gcd = 0;
    
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        gcd = __algo_gcd(gcd, a);
        
    }
    
    if(gcd>1){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
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