#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float double

void solve(){
    float x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    float euclideanDistance, manhattanDistance;
    euclideanDistance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
    manhattanDistance = abs(x2 - x1) + abs(y2 - y1);

    cout << fixed << setprecision(7) << euclideanDistance << " " << manhattanDistance << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}