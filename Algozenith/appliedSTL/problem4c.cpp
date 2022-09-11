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
    int q;
    cin >> q;
    multiset<int> in;
    for (int i = 0; i < q; i++)
    {
        string ss;
        cin >> ss;
        if(ss=="add"){
            int t;
            cin >> t;
            in.insert(t);
        }else if (ss=="erase")
        {
            int t;
            cin >> t;
            multiset<int>::iterator itr = in.find(t);
            if(itr!=in.end()){
            in.erase(itr);
            }
        } else if(ss=="eraseall"){
            int t;
            cin >> t;
            in.erase(t);
        }else if (ss=="count"){
            int t;
            cin >> t;
            cout << in.count(t) << endl;

        }else if(ss=="print"){
            for (multiset<int>::iterator i = in.begin(); i != in.end();i++){
                cout << *i << " ";
            }
            cout << endl;
        }else if(ss=="empty"){
            in.clear();
        }else if(ss=="find"){
            int t;
            cin >> t;
            multiset<int>::iterator itr = in.find(t);
            if (itr != in.end())
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
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