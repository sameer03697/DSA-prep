// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <map>
#include <set>
#include <queue>
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n, k;
    cin >> n>> k;
    int arr[n];
    map<int, deque<int>> indexMap;
    for (int i = 0; i < n; i++)
    {
        /* code */
        cin >> arr[i];
        if(indexMap.find(arr[i])!=indexMap.end()){
            indexMap[arr[i]].push_back(i);
        }else{
            deque<int> dq;
            dq.push_back(i);
            indexMap[arr[i]] = dq;
        }
    }
    // for(auto &z: indexMap){
    //     cout << z.first<<"--->";
    //     deque<int> indexList = z.second;
    //     for (auto &z: indexList)
    //     {
    //         /* code */
    //         cout << z << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     /* code */
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    priority_queue<pair<int, int>> freqNum;
    for (auto &z : indexMap)
    {
        freqNum.push({((int)z.second.size()), z.first});
    }
    //replace indexes of large elems with negative nums
    int count = -1;
    for (int i = 0; i < k; i++)
    {
        /* code */
        auto elem = freqNum.top();
        int num = elem.second;
        if (elem.first==1){
            break;
        }
        int index = indexMap[num].front();
        arr[index] = count;
        indexMap[num].pop_front();
        freqNum.pop();
        freqNum.push({((int)indexMap[num].size()), num});
        count=count -1;
    }
    // cout << "changed indexMap" << endl;
    // for (auto &z : indexMap)
    // {
    //     cout << z.first<<"--->";
    //     deque<int> indexList = z.second;
    //     for (auto &z: indexList)
    //     {
    //         /* code */
    //         cout << z << " ";
    //     }
    //     cout << endl;
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     /* code */
    //     cout << arr[i] << " ";
    // }
    // cout << endl;

    int ans=0;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        if(indexMap.find(arr[i])!=indexMap.end()){
            temp = indexMap[arr[i]].size();
            
        }
        if(temp==0 && indexMap.find(arr[i])==indexMap.end()){
                temp = 1;
        }
        
        ans = ans + n - temp;
        
    }
    cout << ans/2 << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}