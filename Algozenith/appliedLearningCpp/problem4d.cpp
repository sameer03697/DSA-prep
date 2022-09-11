
#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int main() {
    IOS
    int t;
    cin >> t;
    while (t--) {
        int q, n;
        cin >> q >> n;
        if(q==1) {
            bool is_perf_sq = 0;
            for (int i = 1; i*i <= n; ++i) {
                if(i*i == n) {
                    is_perf_sq = 1;
                }
            }
            if(is_perf_sq) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
        else {
            bool is_perf_cube = 0;
            for (int i = 1; i*i*i <= n; ++i) {
                if(i*i*i == n) {
                    is_perf_cube = 1;
                }
            }
            if(is_perf_cube) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }
    return 0;
}
