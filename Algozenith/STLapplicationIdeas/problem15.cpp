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
  // taking inputs
  int Alice[n], Bob[n];
  for (int i = 0; i < n;i++){
    cin >> Alice[i];
  }
  for (int i = 0; i < n; i++){
    cin >> Bob[i];
  }

  //preparing for optimal pick
  deque<pair<int,int>> dq;
  for (int i = 0; i < n; i++){
    dq.push_back({-(Alice[i] + Bob[i]), i});
  }
  sort(dq.begin(), dq.end());

  //game starts
  int sumA = 0, sumB = 0;
  for (int i = 0; i < n;i++){
    if(i%2==0){
      sumA += Alice[dq[i].second];
    }else{
      sumB += Bob[dq[i].second];
    }
  }
  if(sumA>sumB){
    cout << "Alice" << endl;
  }else if(sumA==sumB){
    cout << "Tie" << endl;
  }else if(sumA<sumB){
    cout << "Bob" << endl;
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