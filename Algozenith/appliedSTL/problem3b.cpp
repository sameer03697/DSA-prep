// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
#include <deque>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

struct point
{
    int first, second;
    
};

struct cmp
{
    bool operator()(const point &a, const point &b) const
    {
        return a.second > b.second;
    }
};

bool compare(point a, point b)
{
    return a.second > b.second;
}

void solve()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    // set(pos, value)

    deque<point> ss;
    // cout << "code is here1" << endl;
    deque<int> dq;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(temp);
    }
    // cout << "code is here2" << endl;
    // insert first k elements in set
    for (int i = 0; i < k; i++)
    {
        ss.push_back({i, dq.at(i)});
    }

    sort(ss.begin(), ss.end(), compare);

    cout << ss.front().second;

    for (int i = k; i < n; i++)
    {
        int t;
        t = dq.at(i);

        while (!ss.empty() && t > ss.back().second)
        {
            ss.pop_back();
        }
        ss.push_back({i, t});

        point temp;
        temp = ss.front();
        while (temp.first <= i - k)
        {
            ss.pop_front();
            temp = ss.front();
        }
        cout << " " << temp.second;
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