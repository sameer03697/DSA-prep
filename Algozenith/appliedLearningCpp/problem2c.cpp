#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

#define endl '\n';

void solve()
{
    int N, M;
    cin >> N >> M;

    string row = string("*..");
    for (int i = 0; i < M - 1; i++)
    {
        row += string("*..");
    }
    row += string("*");

    for (int j = 0; j < N; j++)
    {
        cout << string(M * 3 + 1, '*') << endl;

        cout << row << endl;
        cout << row << endl;
    }

    cout << string(M * 3 + 1, '*') << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}