// #include <bits/stdc++.h>
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
    stack<int> addS;
    stack<int> popS;
    // cout << "i am here" << endl;
    int q;
    cin >> q;
    for (int i=0; i < q;i++){
        // cout << "i am here" << endl;
        string s;
        cin >> s;
        if (s=="push"){
            int e;
            cin >> e;
            addS.push(e);
        }
        if(s=="pop"){
            if(!popS.empty()){
                cout << popS.top() << endl;
                popS.pop();
            }else if (!addS.empty()) {
                while(!addS.empty()){
                    popS.push(addS.top());
                    addS.pop();
                }
                cout << popS.top() << endl;
                popS.pop();
            }else{
                cout << 0 << endl;
            }
        }
        if(s=="front"){
            if(!popS.empty()){
                cout << popS.top() << endl;
                
            }else if (!addS.empty()) {
                while(!addS.empty()){
                    popS.push(addS.top());
                    addS.pop();
                }
                cout << popS.top() << endl;
            }else{
                cout << 0 << endl;
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