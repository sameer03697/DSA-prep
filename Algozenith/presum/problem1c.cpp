// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#include <deque>
#define int long long
#define float long double
#define endl '\n'

void solve(){
  int n, m, q;
  cin >> n >> m >> q;
  deque<pair<int, int>> dq;
  for (int i = 0; i < n;i++){
    int temp;
    cin >> temp;
    dq.push_back({temp, 0});
  }

  for (int i = 0; i < m;i++){
    int l, r;
    cin >> l >> r;
    l -= 1;
    r -= 1;
    dq[l].second++;
    if(r+1< dq.size()){
      dq[r+1].second--;
    }
  }
  
  for (int i = 1; i < n;i++){
    dq[i].second += dq[i - 1].second;
  }
  sort(dq.begin(), dq.end());

  //{1,1,2,2,3,3} --> {(1,2),(2,2),(3,2)}
  vector<int> vc(dq.size());
  vc[0] = dq[0].second;
  for (int i = 1; i < dq.size(); i++)
  {
    vc[i] = vc[i - 1] + dq[i].second;
  }

  //vc-[2,4,6]
  for (int i = 0; i < q; i++)
  {
    int num;
    cin >> num;
    auto itr = lower_bound(vc.begin(), vc.end(), num);
    itr++;
    int index = itr - vc.begin();
    // cout << "index: " << index << endl;
    if (index-1<dq.size())
    {
      
      cout << dq[index-1].first << " ";
    }
    else
    {
      cout << "-1" << " ";
    }
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