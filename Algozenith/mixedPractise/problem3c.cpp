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
    int q, x;
    cin >> q >> x;
    int arr[x];
    set<int> mexs;
    mexs.insert(0);
    set<int> vc;
    for (int i = 0; i < x; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < q; i++)
    {
        /* code */
        int y, elem;
        cin >> y;
        elem = arr[y % x];
        vc.insert(elem);
        if (mexs.find(elem) != mexs.end())
        {
            mexs.erase(elem);
            // cout << "removed elem from mex"<<elem << endl;
        }
        if (vc.find(elem + 1) == vc.end())
        {
            mexs.insert(elem + 1);
            // cout << "added elem +1 from mex"<<elem + 1 << endl;
        }
        arr[y % x] = elem + x;

        auto itr = mexs.begin();
        cout << *itr << " ";
    }
    cout << endl;
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