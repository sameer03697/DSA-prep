// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double

void solve()
{
    int dice[7];
    for (int i = 0; i < 6; i++)
    {
        cin >> dice[i+1];
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]=='S'){
            int temp = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = dice[1];
            dice[1] = temp;
        }
        if (s[i]=='N'){
            int temp = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = dice[1];
            dice[1] = temp;
        }
        if (s[i]=='E'){
            int temp = dice[6];
            dice[6] = dice[3];
            dice[3] = dice[1];
            dice[1] = dice[4];
            dice[4] = temp;
        }
        if (s[i]=='W'){
            int temp = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = dice[1];
            dice[1] = temp;
        }
    }
    cout << dice[1] << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}