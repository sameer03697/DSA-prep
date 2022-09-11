// #include <bits/stdc++.h>
#include <stack>
#include <set>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int q;
    cin >> q;
    set<int> ss;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if (s=="add"){
            int t;
            cin >> t;
            ss.insert(t);
        }else if (s=="erase")
        {
            int t;
            cin >> t;
            ss.erase(t);
        }   
        else if (s=="find")
        {
            int t;
            cin >> t;
            if (ss.count(t))
            {
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        } else if(s=="print")
        {
            for (auto i : ss){
                cout << i << " ";
            }
            cout << endl;
        } else if (s=="empty"){
            ss.clear();
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}