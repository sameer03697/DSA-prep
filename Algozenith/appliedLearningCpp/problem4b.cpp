#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

void solve(){

    int n;
    cin >> n;
    if (n==2){
        cout << "YES" << endl;
        return;
    } else if (n<2){
        cout << "NO" << endl;
        return;
    }
    int i = 2;
    bool is_prime = true;
    while (i<=sqrt(n))
    {
        if (n%i == 0){
            is_prime = false;
            break;
        }
        i++;
    }
    if(is_prime){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}