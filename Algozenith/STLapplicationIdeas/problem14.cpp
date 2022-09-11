// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
#include <assert.h>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
  int n=1;
  cin >> n;
  int a[n + 2];
  for (int i = 1; i < n+1;i++){
    cin >> a[i];
  }

  a[0] = INT_MIN;
  a[n + 1] = INT_MIN;
  int L[n + 2], R[n + 2];
  L[0] = 0;
  stack<int> minStack;
  minStack.push(0);
  for (int i = 1; i < n + 1; i++)
  {
    while(!minStack.empty() && a[i]<=a[minStack.top()]){
      minStack.pop();
    }
    L[i] = minStack.top();
    minStack.push(i);
  }
  
  R[n+1] = n+1;
  stack<int> rStack;
  rStack.push(n + 1);
  for (int i = n; i > 0; i--)
  {
    assert(!rStack.empty());
    while (!rStack.empty() && a[i] <= a[rStack.top()])
    {
      rStack.pop();
    }
    R[i] = rStack.top();
    rStack.push(i);
  }



  // cout << "print array "
  //      << "a " << endl;
  // for (int i = 1; i < n + 1; i++)
  // {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // cout << "print array "
  //      << "L " << endl;
  // for (int i = 1; i < n + 1; i++)
  // {
  //   cout << L[i] << " ";
  // }
  // cout << endl;
  // cout << "print array "
  //      << "R " << endl;
  // for (int i = 1; i < n + 1; i++)
  // {
  //   cout << R[i] << " ";
  // }
  // cout << endl;

  deque<int> dq(n + 2, 0);
  // 2 4 5 6 2
  // 0 1 2 3 1
  // 5 3 5 5 6

  // 1 6 6 6 6
  // 0 1 1 1 1
  // 6 6 6 6 6

  // 8 6 1 1
  // 0 0 0 0
  // 2 3 5 5

  for (int i = 1; i < n + 1; i++)
  {
    int length = R[i] - L[i] - 1;
    dq[length] = max(dq[length], a[i]);
  }
  // 1 2 3 4
  // 8 6 0 1

  for (int i = n - 1; i > 0; i--)
  {
    dq[i] = max(dq[i + 1], dq[i]);
  }
  // 8 6 1 1

  for (int i = 1; i < n + 1;i++){
    cout << dq[i] << " ";
  }
  cout << endl;

  // cout << "print array "
  //      << "a " << endl;
  // for (int i = 1; i < n + 2; i++)
  // {
  //   cout << a[i] << " ";
  // }
  // cout << endl;
  // cout << "print array "
  //      << "l " << endl;
  // for (int i = 1; i < n + 2; i++)
  // {
  //   cout << L[i] << " ";
  // }
  // cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}