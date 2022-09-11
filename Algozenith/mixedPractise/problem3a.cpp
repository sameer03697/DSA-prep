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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty()&& a[st.top()]>=a[i])
        {
            st.pop();
        }
        if(st.empty()){
            cout << 0 << " ";
        }else{
            cout << st.top() + 1 << " ";
        }
        st.push(i);
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}