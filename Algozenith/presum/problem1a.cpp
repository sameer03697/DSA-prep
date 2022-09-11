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

int md = (int)1e9 + 7;

int add(int x, int y){
  int ans= (x + y) % md;
  if(ans<0)
    ans += md;
  return ans;
}

int sub(int x, int y){
  int ans = (x - y) % md;
  if(ans<0)
    ans += md;
  return ans;
}
void solve()
{
  int n,q;
  cin >> n>>q;
  int a[n];
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  int pre[n];
  pre[0] = a[0];
  for (int i = 1; i < n; i++)
  {
    pre[i] = pre[i - 1] + a[i];
  }
  for (int i = 0; i < q;i++){
    int l, r;
    cin >> l >> r;
    l -= 2;
    r -= 1;
    if(l<0){
      cout << sub(pre[r], 0) << endl;
      continue;
    }
    cout << sub(pre[r], pre[l]) << endl;
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