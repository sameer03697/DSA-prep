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
    int n, q;
    cin >> n >> q;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    // cout << "print sorted array:";
    // for (int i = 0; i < n;i++){
    //     cout << arr[i];
    // }
    // cout << endl;
    for (int i = 1; i < n; i++)
    {
        /* code */
        arr[i] += arr[i - 1];
    }
    for (int i = 0; i < q; i++)
    {
        /* code */
        int val;
        cin >> val;
        cout << upper_bound(arr, arr + n, val) - arr << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>> _t; while(_t--)
    solve();
}