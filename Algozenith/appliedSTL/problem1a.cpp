// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double

void solve()
{
    int a;
    cin >> a;
    vector<int> myVector;
    string s;
    int x;
    for (int i = 0; i < a; i++)

    {
        cin >> s;
        if (s == "add")
        {
            cin >> x;
            myVector.push_back(x);
        }
        if (s == "print")
        {
            // cout << myVector.size() << endl;
            cin >> x;
            if (x < myVector.size())
            {
                cout << myVector[x] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
        if (s == "remove")
        {
            if(!myVector.empty()) myVector.pop_back();
        }
        if (s == "clear")
        {
            myVector.clear();
        }
    }
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