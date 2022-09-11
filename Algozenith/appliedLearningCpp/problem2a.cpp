#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int sumA = 0;
    int temp;
    for (int i = 0; i < n;i++){
        cin >> temp;
        sumA += temp;
    }
    int sumB = 0;
    for (int i = 0; i < n-1;i++){
        cin >> temp;
        sumB += temp;
    }
    int sumC = 0;
    for (int i = 0; i < n-2;i++){
        cin >> temp;
        sumC += temp;
    }

    cout << sumA - sumB << " "<< sumB - sumC << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}