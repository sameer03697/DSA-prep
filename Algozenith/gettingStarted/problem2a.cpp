#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define end '\n'

void solve(){
    int a;
    cin >> a;
    int b;
    cin >> b;

    cout << 1LL * a * b << end;
    cout << a + b << end;
    cout << a - b << end;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}