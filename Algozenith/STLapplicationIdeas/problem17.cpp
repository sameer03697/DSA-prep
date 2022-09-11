// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#include <map>
#define int long long
#define float long double
#define endl '\n'

void solve(){
  string str;
  getline(cin, str);
  int n = str.length();
  stack<pair<string, int>> st;
  map<string, int> freq;
  for (int i = 0; i < n; i++)
  {
    if(str[i]=='('){
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      st.push({"(", -1});
    }
    if(str[i]==')'){
      int multiplier = 0;
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      while(i+1<n && str[i+1]>='0'&&str[i+1]<='9'){
        multiplier *= 10;
        int num = str[i + 1] - '0';
        multiplier += num;
        i++;
      }
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      if(!multiplier)
        multiplier = 1;
      stack<pair<string, int>> temp;
      while (!st.empty() && st.top().first != "(")
      {
        auto it = st.top();
        temp.push({it.first, it.second * multiplier});
        st.pop();
      }
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;

      // if(st.empty())
      //   throw invalid_argument("stack is empty");
      // if(st.empty() || st.top().first!="(")
      //   throw invalid_argument("Error in the logic");
      st.pop();
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      while(!temp.empty()){
        //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
        st.push(temp.top());
        temp.pop();
        //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      }
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;

    }
    if(str[i]>='A'&&str[i]<='Z'){
      string atom = "";
      atom+=str[i];
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;

      while (i + 1 < n && str[i+1]>='a'&&str[i]<='z'){
        atom += str[i + 1];
        i++;
      }
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
      // cout << "value of i:"<< i << endl;
      int count = 0;
      while (i + 1 < n && str[i + 1] >= '0' && str[i+1] <= '9')
      {
        //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;
        count *= 10;
        int num = str[i + 1] - '0';
        count += num;
        i++;
      }
      // cout << "value of i:"<< i << endl;
      //cout << "error not here  __LINE__"<<str[i]<< __LINE__ << endl;

      if(!count)
        count = 1;
      st.push({atom, count});
    }
  }
  while(!st.empty()){
    auto itr = st.top();
    freq[itr.first] += itr.second;
    st.pop();
  }
  string ans = "";
  for (auto i : freq)
  {
    ans += i.first;
    if(i.second>1)
      ans += to_string(i.second);
  }
  cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}