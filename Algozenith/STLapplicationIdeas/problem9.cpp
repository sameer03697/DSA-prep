// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve()
{
    int n; //[0,1,1,1,2,2,2,3]
    cin >> n;
    int m = 1 << n;
    int arr[m];
    for (int i = 0; i < m; i++)
    {
        /* code */
        cin >> arr[i];
    }
    sort(arr, arr + m);

    map<int, int> sumsFreq; // {0:0, 1:0, 2:0, 3:1}
    vector<int> subSums; // [0,1, 1, 2, 1, 2, 2, 3]
    sumsFreq[0]++;
    subSums.push_back(0);
    vector<int> ans; //[1]
    for (int i = 0; i < m; i++)
    {
        if (sumsFreq[arr[i]])
        {
            sumsFreq[arr[i]]--;
        }
        else
        {
            ans.push_back(arr[i]);
            vector<int> temp;
            for (auto z : subSums)
            {
                /* code */
                temp.push_back(z + arr[i]);
            }
            for (auto z:temp)
            {
                /* code */
                subSums.push_back(z);
                sumsFreq[z]++;
            }
            sumsFreq[arr[i]]--;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout << ans[i] << " ";
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