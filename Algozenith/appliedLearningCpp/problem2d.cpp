#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

void solve()
{
    int N, M, P;
    cin >> N >> M >> P;
    for (int i = 0; i < 1 + N * (P + 1); i++)
    {
        for (int j = 0; j < 1 + M * (P + 1); j++)

        {
            
            int blockID = ((i % (2 * (P + 1)) - (P + 1)) * (j % (2 * (P + 1)) - (P + 1)) < 0);
            if (i % (P + 1) == 0 || j % (P + 1) == 0)
            {
                cout << "*";
            }
            
    
            else if( (i % (P + 1) == j % (P + 1)) && (blockID == 0) )
            {
                
                cout << "\\";
            }
            else if ((i % (P + 1) == (P + 1) - j % (P + 1)) && !(blockID == 0))
            {
                cout << "/";
            }
            else
            {
                cout << ".";
            }
        }
        cout << endl;
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