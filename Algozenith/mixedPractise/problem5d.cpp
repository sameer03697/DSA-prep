// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <map>
#include <set>

using namespace std;
#include <math.h>
#define int long long int
#define float long double
#define endl '\n'

int md = 1e9 + 7;

int add(int x, int y){
    int ans= (x % md + y % md) % md;
    if(ans<0)
        ans += md;
    return ans;
}
int sub(int x, int y){
    x = x % md;
    y = y % md;
    int ans=(x-y)%md;
    if(ans<0)
        ans += md;
    return ans;

}
int mul(int x, int y){
    x = x % md;
    y = y % md;
    int ans=(x*y)%md;
    if(ans<0)
        ans += md;
    return ans;
}
int binomial_exponent(int a, int b){
    int ans = 1;
    while(b){
        if(b%2)
            ans = ans * a % md;
        b /= 2;
        a = a * a %md;
    }
    return ans;
}
int reducedForm(int x, int y){
    int denom = binomial_exponent(y, md - 2);
    int num = x % md;
    return 1LL*num*denom %md;
}
struct Mean
{
    int sum = 0, count = 0;
    void insert(int x)
    {
        sum = add(sum,x);
        count++;
    }
    void remove(int x)
    {
        sum = sub(sum,x);
        count--;
    }
    int getMean()
    {
        if(count>0)
        return reducedForm(sum,count);
        return -1;
    }
};

struct Median
{
    multiset<int> s1;
    multiset<int> s2;
    void insert(int x)
    {
        
        if (!s1.empty() && *s1.rbegin() >= x)
        {
            s1.insert(x);
        }
        else if (!s1.empty() && *s1.rbegin() < x)
        {
            s2.insert(x);
        } else if(s1.empty()){
            s1.insert(x);
        }
        // cout << "error here in median 2" << endl;
        while (s2.size() > s1.size())
        {
            /* code */
            int temp = *s2.begin();
            s1.insert(temp);
            s2.erase(s2.begin());
        }
        // cout << "error here in median 1" << endl;
        while ((int)s1.size() > (int)s2.size() + 1)
        {
            /* code */
            int temp = *s1.rbegin();
            s1.erase(s1.find(temp));
            s2.insert(temp);
        }
        // cout << "error here in median 3" << endl;
    }

    void remove(int x)
    {
        if (s1.find(x) != s1.end())
        {
            s1.erase(s1.find(x));
        }
        else if (s2.find(x) != s2.end())
        {
            s2.erase(s2.find(x));
        }
        // cout << "removed element from median" << endl;
        while (s2.size() > s1.size())
        {
            /* code */
            int temp = *s2.begin();
            s1.insert(temp);
            s2.erase(s2.begin());
        }
        // cout << "error here in median 1" << endl;
        while ((int)s1.size() > (int)s2.size() + 1)
        {
            /* code */
            int temp = *s1.rbegin();
            s1.erase(s1.find(temp));
            s2.insert(temp);
        }
    }

    int getMedian()
    {
        // cout << "printing middle element" << endl;
        // for (auto i : s1)
        // {
        //     /* code */
        //     cout << i << endl;
        // }

        if(s1.empty()){
            return -1;
        }
        if(s1.size()==s2.size()){
            return (int)reducedForm(add(*s1.rbegin(), *s2.begin()),2);
        };
        return *s1.rbegin();
    }
};

struct Mode
{
    map<int, int> mp;
    set<pair<int, int>> s;
    void insert(int x)
    {
        mp[x]++;
        if (mp[x] > 1)
        {
            s.erase(s.find({-(mp[x] - 1), x}));
        }
        s.insert({-mp[x], x});
    }
    void remove(int x)
    {
        mp[x]--;
        s.erase(s.find({-(mp[x] + 1), x}));
        if (mp[x] > 0)
        {
            s.insert({-mp[x], x});
        }
    }
    int getMode()
    {
        if (!s.empty())
        {
            auto itr = s.begin();
            return itr->second %md;
        }
        return -1;
    }
};

void solve()
{
    int q;
    cin >> q;
    multiset<int, greater<int>> s1;
    multiset<int> s2;
    Mean mean;
    Mode m;
    Median median;
    for (int i = 0; i < q; i++)
    {
        string s;
        cin >> s;

        if (s == "insert")
        {
            int x;
            cin >> x;
            // cout << "error here" << endl;
            mean.insert(x);
            median.insert(x);
            m.insert(x);
        }
        if (s == "remove")
        {
            int x;
            cin >> x;
            // Mode implementation
            // cout << "error here" << endl;
            mean.remove(x);

            median.remove(x);
            m.remove(x);
        }
        if (s == "getMedian")
        {
            // Median implemetation
            cout << median.getMedian() << endl;
        }
        if (s == "getMean")
        {
            cout << fixed << setprecision(0)<<mean.getMean() << endl;
        }
        if (s == "getMode")
        {
            cout << fixed<< m.getMode() << endl;
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