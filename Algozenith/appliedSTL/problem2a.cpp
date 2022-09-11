// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int q;
    cin >> q;
    stack<int> stack;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;
        if(s=="add"){
            int x;
            cin >> x;
            stack.push(x);
        }
        if(s=="print"){
            if(stack.empty()){
                cout << 0 << endl;
            } else{
                cout << stack.top() << endl;
            }
        }
        if(s=="remove"){
            if(!stack.empty())
                stack.pop();
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