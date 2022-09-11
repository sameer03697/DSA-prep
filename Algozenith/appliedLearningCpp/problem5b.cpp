#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
using namespace std;

#define int long long
#define float long double

void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int a1, a2, inter, un;
    a1 = (x2 - x1) * (y2 - y1);
    a2 = (x4 - x3) * (y4 - y3);

    int i1, j1, i2, j2;
    inter = 0;
    i1 = max(x1, x3);
    i2 = min(x2, x4);
    j1 = max(y1, y3);
    j2 = min(y2, y4);
    if((i1<=x2 && i1<=x4) && (i2>=x1 && i2>=x3) && (j1<=y2 && j1<=y4) && (j2>=y1 && j2>=y3)){
        // cout << i1 << " " << j1 << " " << i2 << " " << j2 << " " << endl;
        inter = (i2 - i1) * (j2 - j1);
    }
    un = a1 + a2 - inter;
    cout << inter <<" "<< un << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}