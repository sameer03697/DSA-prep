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

int md = 1e9 + 7;
int add(int x, int y)
{
  int ans = (x + y) % md;
  if(ans<0)
    ans += md;
  return ans;
}
int sub(int x, int y)
{
  int ans = (x - y) % md;
  if(ans<0)
    ans += md;
  return ans;
}
void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  int mt[n+1][m+1];
  memset(mt, 0, sizeof(mt));
  // cout << "Error is not in line : " << __LINE__ << endl;
  for (int i = 1; i < n+1; i++)
  {
    for (int j = 1; j < n+1;j++){
      cin>>mt[i][j];
    }
  }
  // int mt[n+1][m+1];
  
  for (int i = 1; i <= n;i++){
    for (int j = 2; j <= m;j++){
      mt[i][j] += mt[i][j-1];
    }
  }
  for (int i = 1; i <= m;i++){
    for (int j = 2; j <= n;j++){
      mt[j][i] += mt[j-1][i];
    }
  }
    // cout << "Error is not in line : " << __LINE__ << endl;

    // for (int i = 0; i < n+1;i++){
    //   for (int j = 0; j < m + 1;j++){
    //     cout << mt[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    for (int i = 0; i < q; i++)
    {
      int p1x, p1y, p2x, p2y;
      cin >> p1x >> p1y >> p2x >> p2y;
      // cout << p1x << p1y << p2x << p2y;

      int ans = mt[p2x][p2y] - mt[p1x - 1][p2y] - mt[p2x][p1y - 1] + mt[p1x - 1][p1y - 1];
      // cout << "Error is not in line : " << __LINE__ << endl;

      ans = ans % md;
      if (ans < 0)
      {
        ans += md;
      }
      cout << ans << endl;
    }
}
// -1 2 3 -4 2
// 0 0 0* 0 4
// 1 2 4* 3 5
// -1 -5 -2 3 4
// 0 -3 -5 3 -6

// 0 0 0 0 0 0 
// 0 -1 1 4 0 2 
// 0 -1 1 4* 0 6 
// 0 0 4 11* 10 21 
// 0 -1 -2 3 5 20 
// 0 -1 -5 -5 0 9 
// 2,3 3,3
// 1,3 3,2

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}