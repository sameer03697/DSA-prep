// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
#include <algorithm>
using namespace std;

#define int long long
#define float long double

bool comp (pair<string,int> a, pair<string,int> b){
        return a.second < b.second;
    }

void solve(){
    pair<string, int> p;
    int n;
    cin >> n;
    vector<pair<string, int>> vector;
    for (int i = 0; i < n;i++){
        string s;
        int g;
        cin >> s >> g;
        vector.push_back({s,g});
    };
    sort(vector.begin(), vector.end(), comp);

    for (int i = 0; i < vector.size(); i++){
        cout << vector[i].first << " "<< vector[i].second << endl;
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