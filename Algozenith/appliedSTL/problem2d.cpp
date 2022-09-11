// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <queue>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int q;
    cin >> q;
    queue<int> qu;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if(s=="add"){
            int x;
            cin >> x;
            qu.push(x);
        }
        if(s=="print"){
            if(qu.empty()){
                cout << 0 << endl;
            } else{
                cout << qu.front() << endl;
            }
        }
        if(s=="remove"){
            if(!qu.empty())
                qu.pop();
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