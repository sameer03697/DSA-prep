#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve(){
    string N;
    cin >> N;
    int length = N.length();
    int sum = 0;

    for (int i = 0; i < length;i++){
        sum += N[i] - '0';
    }
    cout << sum <<endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}