// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    int a[n], b[n];
    map<float,int> mp;
    float highestFrequencyNum;
    int freq = 0, zeroFreq = 0;
    for (int i = 0; i < n; i++)
    {

        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];

        if(a[i]!=0){
            float temp = (float)b[i] / (float)a[i];
            temp = -temp;
            mp[temp]++;
            if(mp[temp]> freq){
                freq = mp[temp];
                highestFrequencyNum = temp;
            }
        }else if(b[i]!=0){
            //Do nothing
        } else{
            zeroFreq += 1;
        }
    }
    cout << freq + zeroFreq << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}