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

void solve()
{
    string s;
    getline(cin, s);
    // cout << "s string" << s << s.length()<<endl;
    if (s.empty())
    {
        cout << 0 << endl;
        return;
        // cout << "i am here" << endl;
    }
    // cout << "i am here 2" << endl;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << i << s[i] << endl;
        // cout << "i am here 3" << endl;
        char last='a';
        if (!st.empty())
            last = st.top();
        // cout << last << endl;
        if ((s[i] == ')') && (last == '('))
        {
            // cout << "i am here " << i << endl;
            st.pop();
        }
        else
        {
            st.push(s[i]);
        }
        // cout << "stack at the end of " << i << "itr " << st.size() << endl;
    }
    cout << st.size() << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    string temp;
    getline(cin, temp);
    while (_t--)
        solve();
}