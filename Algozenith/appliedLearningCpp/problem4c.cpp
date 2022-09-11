#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
using namespace std;

int getPrimeFatcor(int n){
    if (n==2){
        return 2;
    } else if (n<2){
        return -1;
    }
    int i = 2;
    while (i<=sqrt(n))
    {
        if (n%i == 0){
            return i;
        }
        i++;
    }
    return -1;
}

void solve(){
    int n, r, d;
    cin >> n;
    unordered_map<int,int> umap;
    r = n;
    while(r>1){
    d = getPrimeFatcor(r);
    if (d != -1 && d>1) {
        umap[d]++;
    } else if (d==-1){
        if(r>1){
            // cout << r << d << "remainder1"<< r % d << endl;
            umap[r]++;
            break;
        }else{
            break;
        }
    }
    // cout << r << d << "remainder2"<< r % d << endl;
    r = r / d;
    }
    int number_of_divisors = 1;
    for (auto x : umap)
    {
        // cout << x.first << "prime power"<< x.second<< endl;
        number_of_divisors = number_of_divisors * (x.second + 1);
    }
    cout << number_of_divisors<< endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}