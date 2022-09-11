// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<int> c;
    int a[n], b[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        c.push_back(a[i]-b[i]);
    }
    
    sort(c.begin(), c.end());
    int total=0;
    // vector<int>::iterator itre = c.begin();
    // cout << *itre << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << c[i] << " ";
    // }
    // cout << endl;

    for (auto j = c.begin(); j != c.end(); j++)
    {
        int value = *j;
        // cout << "Place 2:"<<value << endl;
        auto x = upper_bound(c.begin(), j, -value);
        int number = j - x;
        // cout << "Place 1:"<<j-c.begin() <<number << endl;
        total += number;
    }
    cout << total << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}