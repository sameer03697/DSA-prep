// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n, m;
    cin >> n >> m;
    set<int> ss;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        ss.insert(t);
    }
    for (int j = 0; j < m;j++){
        int t;
        cin >> t;
        if(ss.find(t)!=ss.end()){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
            ss.insert(t);
        }
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