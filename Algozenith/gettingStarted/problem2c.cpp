#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(){
    long long n;
    cin >> n;
    cout << n * (n - 1) / 2 << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}