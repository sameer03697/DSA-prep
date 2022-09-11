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
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int currDifference, number, maxNumber;
    currDifference = a[1] - a[0];
    number = 2;
    maxNumber = 2;
    for (int i = 2; i < n; i++)
    {
        if ((a[i]-a[i-1])==currDifference){
            number++;
        } else{
            currDifference = a[i] - a[i - 1];
            number = 2;
        }

        if(number>maxNumber){
            maxNumber = number;
        }
    }
    cout << maxNumber << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}