// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#include <unordered_set>
#include <unordered_map>
#define int long long
#define float long double
#define endl '\n'

int n;
//MAP: {1:aparna, 2:sameer} Index
//Set: {1,2,3,4}
// 0: begin
// n: end
void solve(){
    cin >> n;
    // create und
    unordered_set<int> list;
    int temp,count=0;
    for (int i = 0; i < n;i++){
        cin >> temp;
        if(list.find(temp)!= list.end()){
            count++;
        }else{
            list.insert(temp);
        }
    }
    // delete uno
    cout << count << endl;
}

// a1, a2, a3, a4, .. , a500 
//(i,j)
// i<j
// a[j]-a[i]=X
// 9 3
// 1 2 3 3 4 5 6 6 7

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // int _t;cin>> _t; while(_t--)
    solve();
}