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

struct MonotoneDq
{
    deque<int> dq;

    void insert(int x){
        while(!dq.empty() && dq.back()<x){
            dq.pop_back();
        }
        dq.push_back(x);
    }
    void removeFirstElem(int x){
        if(!dq.empty()&&dq.front()==x){
            dq.pop_front();
        }
    }
    int getMax(){
        return dq.front();
    }
};

void solve(){
    int n, k;
    cin >> n >> k;
    MonotoneDq dq;
    int ar[n];
    for (int i = 0; i < n; i++)
    {
        /* code */
        int temp;
        cin >> temp;
        ar[i] = temp;
    }

    for (int i = 0; i < k; i++)
    {
        /* code */
        
        dq.insert(ar[i]);
    }
    cout << dq.getMax() << " ";
    for (int i = k; i < n; i++)
    {
        /* code */
        dq.insert(ar[i]);
        dq.removeFirstElem(ar[i - k]);
        cout << dq.getMax() << " ";
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