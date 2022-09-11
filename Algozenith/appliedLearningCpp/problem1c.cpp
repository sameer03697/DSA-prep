#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;

    if ((a== -1)|| (b== -1)){
        cout << "F" << endl;
    } else if (a + b >= 80) {
        cout << "A" << endl;
    } else if (a+b >= 65 && a+b <80) {
        cout << "B" << endl;
    } else if (a+b >= 50 && a+b <65) {
        cout << "C" << endl;
    } else if (a+b >= 30 && a+b < 50 ){
        if (c >= 50){
            cout << "C" << endl;
        }
        else
        {
            cout << "D" << endl;
        }
    } else if (a+b < 30){
        cout << "F" << endl;
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