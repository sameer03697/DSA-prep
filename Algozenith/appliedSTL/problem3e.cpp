// #include <bits/stdc++.h>
#include <set>
#include <stack>
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
    set<int> ss,ns;
    for (int i = 0; i < q; i++)
    {
        int type, num;
        cin >> type >> num;
        if(type==1){
            ss.insert(num);
            ns.erase(num);
            if(!ns.count(num+1)){
                ns.insert(num + 1);
            }
        }
        else if (type == 2)
        {
            if(!ss.count(num)){
            cout << num << endl;
            } else{
                cout << *ns.lower_bound(num) << endl;
            }
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