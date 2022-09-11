// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int q;
    cin >> q;
    map<string, int> m;
    for (int i = 0; i < q; i++)
    {
        string ss;
        cin >> ss;
        if (m.count(ss)>0)
        {
            cout << ss << m[ss] << endl;
            m[ss]++;
        } else
        {
            m[ss] = 1;
            cout << "OK" << endl;
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