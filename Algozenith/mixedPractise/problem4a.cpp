// #include <bits/stdc++.h>
#include <stack>
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
#include <math.h>
#define int long long
#define float long double
#define endl '\n'

struct notification
{
    int index, application, read;
};

void solve()
{
    int n, q;
    cin >> n >> q;
    int unread = 0, messages = 0, queueRead = 0;
    deque<notification> dq;
    vector<deque<int>> applicationQ;
    for (int i = 0; i < n + 1; i++)
    {
        deque<int> temp;
        applicationQ.push_back(temp);
    }
    // cout << "I am here" << endl;
    for (int i = 0; i < q; i++)
    {
        /* code */
        int queryType, num, currSize;
        cin >> queryType >> num;
        currSize = dq.size();
        if (queryType == 1)
        {
            // cout << "In querytype 1" << endl;
            notification temp;
            temp.index = currSize;
            temp.application = num;
            temp.read = 0;
            dq.push_back(temp);
            messages += 1;
            unread += 1;
            applicationQ[num].push_back(temp.index);
        }

        if (queryType == 2)
        {
            // cout << "In querytype 2" << endl;
            while (!applicationQ[num].empty())
            {
                int tempIndex = applicationQ[num].front();
                int readStatus = dq[tempIndex].read;
                if (readStatus == 0)
                {
                    dq[tempIndex].read = 1;
                    unread -= 1;
                }
                applicationQ[num].pop_front();
            }
        }

        if (queryType == 3)
        {
            if (queueRead < num)
            {
                // cout << "In querytype 3 print" << endl;
                for (; queueRead < num; queueRead++)
                {
                    /* code */
                    if (dq[queueRead].read == 0)
                    {
                        dq[queueRead].read = 1;
                        unread -= 1;
                    }
                }
            }
        }
        // cout << "I am here before unread print" << endl;
        cout << unread << endl;
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