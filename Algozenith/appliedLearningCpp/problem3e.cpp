#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve()
{

    int n;
    cin >> n;
    int prev = 0;
    long long total = 0;
    int curr = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> curr;
        if (curr >= prev)
        {
            prev = curr;
        }
        else
        {
            total += prev - curr;

        }
    }
    cout << total << endl;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}