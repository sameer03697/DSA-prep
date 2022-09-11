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

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    auto itr1 = a.begin();
    auto itr2 = b.begin();
    vector<int> uni, inte, diff;
    while (itr1 != a.end() && itr2 != b.end())
    {
        if (*itr1 == *itr2)
        {
            inte.push_back(*itr1);
            uni.push_back(*itr1);
            itr1++;
            itr2++;
        }
        else if (*itr1 < *itr2)
        {
            uni.push_back(*itr1);
            diff.push_back(*itr1);
            itr1++;
        }
        else if (*itr1 > *itr2)
        {
            while (itr2 != b.end() && (*itr1 > *itr2))
            {
                uni.push_back(*itr2);
                itr2++;
            }
        }
    }
    while ((itr1 != a.end()) && (itr2 == b.end()))
    {
        uni.push_back(*itr1);
        diff.push_back(*itr1);
        itr1++;
    }
    while ((itr1 == a.end()) && (itr2 != b.end()))
    {
        uni.push_back(*itr2);
        itr2++;
    }

    for (auto i : uni)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : inte)
    {
        cout << i << " ";
    }
    cout << endl;
    for (auto i : diff)
    {
        cout << i << " ";
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