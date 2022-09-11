// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double

void solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }
    sort(vec.begin(), vec.end());
    int pairs = 0;
    for (int i = 0; i < n; i++)
    {
        auto up = upper_bound(vec.begin(), vec.end(), x - vec[i]);
        if (up - vec.begin() >= n)
        {
            pairs += n;
        }
        else
        {
            cout << x-vec[i] << " " <<up - vec.begin()  << endl;
            pairs += up - vec.begin() ;
        }
    }
    int samePairs = 0;
    for (int i = 0; i < n;i++){
        if(vec[i]+vec[i]<=x){
            samePairs++;
        }
    }
        cout << pairs-samePairs << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}