#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

long double PI = acos(-1.0);

void solve(){
    long double R;
    cin >> R;
    cout <<fixed<<setprecision(9)<< PI *R *R << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //int _t;cin>> _t; while(_t--)
    solve();
}