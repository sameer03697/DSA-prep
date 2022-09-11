// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <unordered_map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int num, denom;
    cin >> num >> denom;
    
    int isNegative=0;
    if(num*denom<0)
        isNegative = 1;
    denom = abs(denom);
    num = abs(num);
    string ans = "";
    int integerPart = num / denom;
    if(isNegative)
        ans += "-";
    ans += to_string(integerPart);
    if (num%denom)
    ans += ".";
    
    int remain = num % denom;
    unordered_map<int, int> remMap;
    int recourPosition = -1;
    while (1)
    {
        if(!remain)
            break;
        if(remMap.find(remain)==remMap.end()){

            int pos = ans.length();
            remMap[remain] = pos;
            remain = remain * 10;
            ans += to_string(remain / denom);
            remain = remain % denom;
        }else{
            recourPosition = remMap[remain];
            break;
        }
    }
    // cout << num << denom << endl;
    // cout << recourPosition << " answer "<<ans << endl;
    if (recourPosition != -1)
        cout << ans.substr(0, recourPosition) + "(" + ans.substr(recourPosition, ans.length()-recourPosition) + ")" << endl;
    else
        cout << ans << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}