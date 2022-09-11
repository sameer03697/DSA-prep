// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#include <queue>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n=0;
    cin >> n;
    priority_queue<int> pq;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int x;
        cin >> x;
        if (x < ans + 1)
        {
            cout << ans << " ";
        }
        else
        {
            pq.push(-x);
            if (pq.size() >= ans + 1)
            {
                ans++;
            }
            // clear top
            while (!pq.empty()&&-pq.top() <= ans)
            {
                /* code */
                pq.pop();
            }
            cout << ans << " ";
        }
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
    while (_t--){
        // cout << "value of t" << _t<<endl;
        solve();
    }
}