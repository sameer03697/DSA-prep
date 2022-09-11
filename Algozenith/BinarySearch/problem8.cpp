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

int n;
int median;
vector<int> arr;
bool check(int x){
    // cout << " for Value of x " << x<<endl;
    // for (auto i : arr)
    // {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    // 10
    // 1 3 5 6 7 8
    // output:
    int currSum = 0;
    int cnt = 0;
    int start = 1;
    int end = 1;
    while (start <= n && end <=n)
    {
        // cout << "here" << endl;
        currSum += arr[end]; // 1() 4 9 15(14, 11, 6) 13 (7)

        while(currSum>x && start<n){
            currSum -= arr[start];
            start++;// start: 1 1 1 2(3, 4) 5
        }
        // cout << currSum<<"Here" << endl;
        
        if(currSum<=x){
            // cout << "Here" << endl;
            cnt += end - start + 1; // 1 2 3 3(4) 5()
        }
        end++;// 2 3 4 5
    }
    // cout << "final Count:" << cnt << endl;
    // cout << "Median:" << median << endl;
    if (cnt >= median)
        return true;
    return false;
}

void solve()
{
    cin >> n;
    arr.resize(n+1);
    arr[0] = 0;
    int totalSum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        totalSum += arr[i];
    }
    // cout << "totalSum :" << totalSum << endl;

    int noSubArrays = n*(n + 1) / 2; //no. of elements
    median = (noSubArrays+1) / 2;
    int lo = 0, hi = totalSum;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo + hi) / 2;
        // cout << mid << endl;
        // cout << "mid: " << mid << " check: " << check(mid) << endl;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout<<ans << endl;
}


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();

    // check(5);
}