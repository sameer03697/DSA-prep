// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n, q;
    cin >> n >> q;
    deque<int> dq;
    int maxLocation = 0, max=0;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        dq.push_back(temp);
        if(temp>max){
            max = temp;
            maxLocation = i;
        };
    }
    deque<pair<int, int>> dqPersist;
    int currentLocation = 0;
    for (int i = 0; i < q; i++)
    {
        /* code */
        int num;
        cin >> num;
        while(num>currentLocation && currentLocation!=maxLocation){
            int first, second, temp;
            first = dq.front();
            dq.pop_front();
            second = dq.front();
            dq.pop_front();
            dqPersist.push_back({first, second});
            if(first>=second){
                dq.push_front(first);
                dq.push_back(second);
            }
            else
            {
                dq.push_front(second);
                dq.push_back(first);
            }
            currentLocation++;
        }
        pair<int, int> result;
        if (num - 1 < maxLocation)
        {
            result.first = dqPersist[num - 1].first;
            result.second = dqPersist[num - 1].second;
        } else if(num -1 == maxLocation){
            result.first = dq[0];
            result.second = dq[1];
        } else if(num-1> maxLocation){
            result.first = dq[0];
            int index = ((num - 1) - maxLocation) % ((int)dq.size() - 1);
            index = index + 1;
            result.second = dq[index];
        }
        cout << result.first << " " << result.second << endl;
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