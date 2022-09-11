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
    int n;
    int q;
    cin >> n >> q;
    vector<int> myVec;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        myVec.push_back(temp);
    }
    sort(myVec.begin(), myVec.end());
    int first, last;
    first = myVec.front();
    last = myVec.back();

    vector<int>::iterator low, up;
    for (int i = 0; i < q; i++)
    {
        int type, num;
        cin >> type >> num;
        if (type == 1)
        {
            if (num > last)
            {
                cout << -1 << " ";
            }
            else if (num == last)
            {
                cout << last << " ";
            }
            else
            {
                up = upper_bound(myVec.begin(), myVec.end(), num);
                if (myVec[up - myVec.begin() - 1] == num)
                {
                    cout << myVec[up - myVec.begin() - 1] << " ";
                }
                else
                {
                    cout << myVec[up - myVec.begin()] << " ";
                };
            }
        };
        if (type == 2)
        {
            if (num >= last)
            {
                cout << -1 << " ";
            }
            else
            {
                up = upper_bound(myVec.begin(), myVec.end(), num);
                cout << myVec[up - myVec.begin()] << " ";
            }
        };
        if (type == 3)
        {
            if (num >= last)
            {
                cout << myVec.size() << " ";
            }
            else
            {
                up = upper_bound(myVec.begin(), myVec.end(), num);
                cout << up - myVec.begin() << " ";
            }
        };
        if (type == 4)
        {
            if (num <= first)
            {
                cout << 0 << " ";
            }
            else if (num > last)
            {
                cout << myVec.size() << " ";
            }
            else
            {
                low = lower_bound(myVec.begin(), myVec.end(), num);
                if (myVec[low - myVec.begin()] == num)
                {
                    cout << low - myVec.begin() << " ";
                }
                else
                {
                    cout << low - myVec.begin() << " ";
                };
            }
        };
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