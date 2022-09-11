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

int preference(char c)
{
    if (c == '+')
    {
        return 1;
    }
    if (c == '-')
    {
        return 2;
    }
    if (c == '*')
    {
        return 3;
    }
    if (c == '/')
    {
        return 4;
    }
    if (c == '^')
    {
        return 5;
    }
    if (c == '('){
        return -1;
    }
    return -1;
}

void solve()
{
    string s;
    cin >> s;
    stack<char> ss;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        if (!ss.empty())
        {
            // cout << "ss is not empty for " << i << "top element" << ss.top() << "size"<< ss.size() << endl;
        }

        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            ss.push(s[i]);
        }
        else if (s[i] == ')')
        {
            // cout << "ss is not empty for ) iteration " << i << "top element" << ss.top()<< "size"<< ss.size() << endl;
            while (!ss.empty() && ss.top() != '(')
            {
                ans += ss.top();
                // cout << "ss is not empty for ) iteration " << i << "top element" << ss.top() << "size"<< ss.size() << endl;
                ss.pop();
                // cout << "ss is not empty for ) iteration " << i << "top element" << ss.top()<< "size"<< ss.size() << endl;
            }
            if (!ss.empty() && ss.top() == '(')
            {
                ss.pop();
            }
        }
        else if (!ss.empty())
        {
            if (preference(s[i]) > preference(ss.top()))
            {
                ss.push(s[i]);
            }
            else
            {
                while (preference(ss.top()) > preference(s[i]))
                {
                    ans += ss.top();
                    ss.pop();
                    if (ss.empty())
                    {
                        break;
                    }
                }
                ss.push(s[i]);
            }
        }
        else
        {
            if (ss.empty())
            {
                ss.push(s[i]);
            }
        }
    }
    while (!ss.empty())
    {
        ans += ss.top();
        ss.pop();
    }
    cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}