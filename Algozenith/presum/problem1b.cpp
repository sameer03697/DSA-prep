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

int n = (int)1e6;

void solve(){
  int number, k, q; // 3 2 3
  cin >> number >> k >> q;
  int a[n];
  for (int i = 0; i < n;i++){
    a[i] = 0;
  }
  //cout << "no error in line: " << __LINE__ << endl;
  // 0 0 0 0
  // 1 4
  // 2 3
  // 2 4
  for (int i = 0; i < number;i++){
    int l, r;
    cin >> l >> r;
    l -= 1;
    r -= 1;
    a[l]++;
    if(r+1<n){
      a[r+1]--;
    }
  }
  //cout << "no error in line: " << __LINE__ << endl;

  // 1 0 0 0
  // 1 1 0 -1
  // 1 2 0 -1

  //cout << "no error in line: " << __LINE__ << endl;
  vector<int> pref(n + 1);
  //cout << "no error in line: " << __LINE__ << endl;
  pref[0] = 0;
  int i = 0;
  //cout << "no error in line: " << __LINE__ << endl;

  try
  {
    for (i = 1; i <= n; i++)
    {
      pref[i] = pref[i - 1] + a[i - 1]; //a is from 0-n-1
    }
  }
  catch(const std::exception& e)
  {
    cout << "error ar value of i " << i << endl;
    std::cerr << e.what() << '\n';
  }
  
  
  // 0 1 3 3 2
  //cout << "no error in line: " << __LINE__ << endl;

  int count = 0;
  vector<int> preCount(n + 1);
  for (int i = 0; i < n + 1; i++)
  {
    if(pref[i]>=k)
      count++;
    preCount[i] = count;
  }
  //cout << "no error in line: " << __LINE__ << endl;

  // 0 0 1 2 3
  // 1 4 --> 3
  // 1 3 ---> 2
  for (int i = 0; i < q;i++){
    int l, r;
    cin >> l >> r;
    cout << preCount[r] - preCount[l - 1] << endl;
  }
  //cout << "no error in line: " << __LINE__ << endl;

}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}