// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <algorithm>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    multiset<int> ms;
    for (int i = 0; i < n;i++){
        int t;
        cin >> t;
        multiset<int>::iterator itr = upper_bound(ms.begin(), ms.end(), t);
        if(itr==ms.end()){
            ms.insert(t);
        } else{
            ms.erase(itr);
            ms.insert(t);
        }
    }
    cout << ms.size() << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}