#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve(){

    int n, value, zeros;
    cin >> n;
    value = n;
    zeros = 0;

    while (value>0){
        zeros += value / 5;
        value = value / 5;
    }
    cout << zeros << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}