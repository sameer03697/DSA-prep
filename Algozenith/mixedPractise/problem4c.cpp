// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <set>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

void solve(){

    string s;
    int q;
    cin >> s;
    cin >> q;
    vector<set<int>> vSet;
    for (int i = 0; i < 26; i++)
    {
        set<int> temp;
        vSet.push_back(temp);
    }

    for (int i = 0; i < s.size(); i++)
    {
        /* code */
        int index = s[i] - 'a';
        vSet[index].insert(i);
    }

    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        if(x==1){
            int index;
            char c;
            cin >> index >> c;
            int vSetOldIndex = s[index - 1] - 'a';
            int vSetNewIndex = c - 'a';
            vSet[vSetOldIndex].erase(index - 1);
            vSet[vSetNewIndex].insert(index - 1);
            s[index - 1] = c;
            // cout << "Value at index changed" << endl;
        } else if (x==2)
        {
            /* code */
            int L, R;
            cin >> L >> R;
            int distinct = 0;
            for (int vSetIndex = 0; vSetIndex < (int)vSet.size();vSetIndex++){
                auto lower = vSet[vSetIndex].lower_bound(L-1);
                if(lower!=vSet[vSetIndex].end() && *lower <= R-1){
                    distinct++;
                }
            }
            cout << distinct << endl;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}