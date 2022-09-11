// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

struct problem6
{
    /* data */
    int sum = 0, max = -1, min = -1;
    map<int, int> mp;
    void add(int x)
    {
        // count++;
        sum += x;
        mp[x]++;
        if (mp.size() != 0)
        {
            max = mp.rbegin()->first;
            min = mp.begin()->first;
        }
        else
        {
            max = -1;
            min = -1;
        }
    }
    void remove(int x)
    {
        // count--;
        if (mp.find(x) != mp.end())
        {
            /* code */
            sum -= x;

            mp[x]--;
            if (mp[x] == 0)
            {
                mp.erase(mp.find(x));
            }
            if (mp.size() != 0)
            {
                max = mp.rbegin()->first;
                min = mp.begin()->first;
            }
            else
            {
                max = -1;
                min = -1;
            }
        }
    }
    void getMax()
    {
        cout << max << endl;
    }
    void getMin()
    {
        cout << min << endl;
    }
    void getSum()
    {
        cout << sum << endl;
    }
};

void solve()
{
    int q;
    cin >> q;
    problem6 ds;
    for (int i = 0; i < q; i++)
    {
        int num;
        cin >> num;
        // cout << "for number" << i;
        if (num == 1 || num == 2)
        {
            int x;
            cin >> x;
            if (num == 1)
            {
                ds.add(x);
            }
            if (num == 2)
            {
                /* code */
                ds.remove(x);
            }
        }
        if (num == 3 || num == 4 || num == 5)
        {
            string str;
            cin >> str;
            if (num == 3)
            {
                ds.getMin();
            }
            if (num == 4)
            {
                /* code */
                ds.getMax();
            }
            if (num == 5)
            {
                ds.getSum();
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}