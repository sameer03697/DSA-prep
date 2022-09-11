#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <unordered_map>
using namespace std;

void solve()
{

    string s;
    s = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<char, int> umap;
    for (int i = 0; i < s.size(); i++)
    {
        umap[s[i]] = i;
    }

    string num;
    int b1, b2;
    cin >> num >> b1 >> b2;
    long long value = 0;

    for (int i = 0; i < num.size(); i++)
    {
        value = b1 * value + umap[num[i]];
    }
    

    string output = "";

    while (1)
    {   
        if (value==0)
            break;
        output = s[value % b2] + output;
        value = value / b2;
    }

    
    if (output==""){
        output = "0";
    }
    cout << output << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}