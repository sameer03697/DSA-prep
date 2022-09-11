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

int maxDiff(set<int> ss)
{
    int first = 0, prev, curr = 0, max = 0;
    auto itr = ss.begin();
    prev = *itr;
    itr++;
    while (itr != ss.end())
    {
        curr = *itr - prev;
        if (max < curr)
        {
            max = curr;
        }
        prev = *itr;
        itr++;
    }
    return max;
}
void solve()
{
    int h, w, n;
    cin >> h >> w >> n;
    set<int> sh, sw;
    sh.insert(0);
    sh.insert(h);
    sw.insert(0);
    sw.insert(w);
    int maxL, maxW;
    maxL = h;
    maxW = w;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s == "H")
        {
            int x;
            cin >> x;
            sh.insert(x);
            maxL = maxDiff(sh);
        }
        else if (s == "V")
        {
            int x;
            cin >> x;
            sw.insert(x);
            maxW = maxDiff(sw);
        }
        cout << maxL * maxW << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}