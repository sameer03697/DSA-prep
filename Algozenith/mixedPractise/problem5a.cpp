// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <deque>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

int modulud(int b, int c, int p)
{
    // cout << "modulud for" << b << " "<< c << " " << p-1 <<endl;
    deque<int> modValDq;
    deque<int> binaryDq;
    int front = b % (p - 1);
    int rem = c;
    while (rem > 0)
    {
        binaryDq.push_front(rem % 2);
        rem = rem / 2;
        modValDq.push_front(front);
        front = (front * front) % (p - 1);
    }
    int remBC = 1;
    for (int i = 0; i < (int)modValDq.size(); i++)
    {
        if (binaryDq[i] == 1)
        {
            remBC = (remBC * modValDq[i]) % (p - 1);
        }
    }
    // cout << remBC << endl;
    return remBC;
}
void solve()
{
    int a, b, c, p;
    cin >> a >> b >> c >> p;
    if (b == 0 && c != 0)
    {
        cout << "1\n";
    }
    else if (!a)
    {
        cout << "0\n";
    }
    else if (a % p == 0)
    {
        cout << "0\n";
    }
    else
    {
        // cout << "I am here" << endl;
        int rem = modulud(b, c, p);
        rem = modulud(a, rem, p + 1);
        cout << rem << endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;
    cin >> _t;
    while (_t--)
        solve();
}