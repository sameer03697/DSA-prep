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

struct point
{
    int x, y;
};
struct cmp
{
    bool operator()(const point &a, const point &b) const
    {
        if (a.x == b.x)
        {
            return a.y < b.y;
        }
        else
        {
            return a.x < b.x;
        }
    }
};

struct path
{
    /* data */
    point one, two;
};

struct cmp2
{
    bool operator()(const path &a, const path &b) const
    {
        int x1, x2, y1, y2;
        int i1, i2, j1, j2;
        x1 = a.one.x;
        x2 = a.two.x;
        y1 = a.one.y;
        y2 = a.two.y;

        i1 = b.one.x;
        i2 = b.two.x;
        j1 = b.one.y;
        j2 = b.two.y;

        if (x1 != i1)
        {
            return x1 < i1;
        }
        if (x2 != i2)
        {
            return x2 < i2;
        }
        if (y1 != j1)
        {
            return y1 < j1;
        }
        return y2 < j2;
    }
};

void solve()
{
    string s;
    cin >> s;
    set<point, cmp> ss;
    point position = {0, 0};
    ss.insert(position);
    set<path,cmp2> paths;
    int result = 0;
    for (auto itr = s.begin(); itr != s.end(); itr++)
    {
        /* code */
        char c = *itr;
        point next;
        if (c == 'N')
        {
            next.x = position.x;
            next.y = position.y + 1;
        }
        if (c == 'S')
        {
            next.x = position.x;
            next.y = position.y - 1;
        }
        if (c == 'E')
        {
            next.x = position.x + 1;
            next.y = position.y;
        }
        if (c == 'W')
        {
            next.x = position.x - 1;
            next.y = position.y;
        }

        path onepath = {position, next};
        path reverse = {next, position};
        if (paths.find(onepath) != paths.end())
        {
            result += 1;
        }
        else
        {
            result += 5;
            paths.insert(onepath);
            paths.insert(reverse);
        }
        // cout << "current position: " << position.x << position.y << endl;
        // cout << "next position: " << next.x << next.y << endl;
        // cout << "result " << result << endl;
        position = next;
    }
    cout << result << endl;
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