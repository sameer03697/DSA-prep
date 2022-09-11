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

struct bag
{
    int k;
    int sum = 0;
    multiset<int> ms;
    multiset<int> remain;
    bag(int n)
    {
        k = n;
    }
    void insert(int x)
    {
        if(ms.size()<k){
            ms.insert(x);
            sum += x;
            return;
        }
        if (x >= *ms.begin())
        {
            ms.insert(x);
            sum += x;
            partionMovement();
            return;
        }
        remain.insert(x);
        return;
    }
    void partionMovement(){
        while(ms.size()!=k){
            if(ms.size()>k){
                sum -= *ms.begin();
                remain.insert(*ms.begin());
                ms.erase(ms.begin());
            }
            if(ms.size()<k && remain.size()>0){
                sum += *remain.rbegin();
                ms.insert(*remain.rbegin());
                remain.erase(remain.find(*remain.rbegin()));
            }
            if(ms.size()<k && remain.size()==0){
                break;
            }
        }
    }
    void remove(int x){
        auto itr = ms.find(x);
        if(itr!=ms.end()){
            ms.erase(itr);
            sum -= x;
            partionMovement();
            return;
        }
        itr = remain.find(x);
        if(itr!=remain.end()){
            remain.erase(itr);
            return;
        }
    }
    int getSum(){
        return sum;
    }
    void debug(){
        cout << "Print ms" << endl;
        ;
        for(auto v: ms){
            cout << v << " ";
        }
        cout << endl;
        cout << "Print remain"<< endl;
        for(auto v: remain){
            cout << v << " ";
        }
        cout << endl;
        cout << "SUM :"<<sum << endl;
    }
};
void solve()
{
    int q,k;
    cin >> q >> k;
    bag bg(k);
    
    for (int i = 0; i < q; i++)
    {
        /* code */
        int x;
        cin >> x;
        // cout << "for i " << i << endl;
        
        if (x == 1)
        {
            int y;
            cin >> y;
            
            bg.insert(y);
        }
        if(x==2){
            int y;
            cin >> y;
            bg.remove(y);
        }
        if(x==3){
            string str;
            cin >> str;
            cout << bg.getSum() << endl;
        }
        // bg.debug();
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}