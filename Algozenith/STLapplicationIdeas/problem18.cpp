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

void solve(){
    int n;
    cin >> n;
    int A[n + 2], L[n + 2], R[n + 2];
    for (int i = 1; i < n+1; i++)
    {
        /* code */
        cin >> A[i];
    }
    A[0] = -1e9;
    A[n + 1] = -1e9;
    stack<int> left;
    left.push(0);
    for (int i = 1; i < n+1; i++)
    {
        /* code */
        while (!left.empty()&& A[left.top()]>=A[i])
        {
            /* code */
            left.pop();
        }
        assert(!left.empty());
        L[i] = left.top();
        left.push(i);
    }

    stack<int> right;
    right.push(n+1);
    for (int i = n; i >0; i--)
    {
        /* code */
        while (!right.empty()&& A[right.top()]>=A[i])
        {
            /* code */
            right.pop();
        }
        assert(!right.empty());
        R[i] = right.top();
        right.push(i);
    }

    int ans = 0, mx = 0;
    //[2,1,2]
    //[0,0,2]
    //[2,4,4]
    for (int i = 1; i < n+1; i++)
    {
        /* code */
        // cout << A[i] << R[i] << L[i] << endl;
        ans = A[i] * (R[i] - L[i]-1);
        mx = max(mx, ans);
    }
    cout << mx << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}