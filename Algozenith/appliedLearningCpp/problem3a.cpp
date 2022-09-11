#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
using namespace std;

void solve(){
    string a;
    cin >> a;
    int q;
    cin >> q;
    while(q--){
    string operation;
    cin >> operation;
    if (operation == "print"){
        int li, ri;
        cin >> li >> ri;
        cout << a.substr(li, ri-li+1) << endl;
    }
    if (operation == "reverse"){
        int li, ri;
        cin >> li >> ri;
        reverse(a.begin() + li, a.begin() + ri +1);
        // cout << a << endl;
    }
    if (operation == "replace"){
        int li, ri;
        cin >> li >> ri;
        string replace;
        cin >> replace;
        for (int i = li; i < ri + 1; i++){
            if(i > a.length())
                cout << "failed";
            a[i] = replace[i - li];
        }
        // cout << a << endl;
    }
    if (operation == "rotate"){
        int k;
        cin >> k;
        a = a.substr(a.length() - k) + a.substr(0, a.length() - k);
        // cout << a << endl;
    }
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