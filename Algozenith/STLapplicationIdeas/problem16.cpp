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

class MinStack {
private:

public:
    stack<int> st;
    int minElem=INT_MAX;
    MinStack() {}

    void push(int x) {
        if(st.empty()){
            st.push(x);
            minElem = x;
            return;
        }
        if(x<minElem){
            st.push(2 * x - minElem);
            minElem = x;
        }else{
            st.push(x);
        }
    }
    // 2*x -minElem1 = y
    // x

    void pop() {
        if(!st.empty()){
            if(st.top()<minElem){
                minElem = 2 * minElem - st.top();
                st.pop();
                return;
            }
            st.pop();
            if(st.empty()){
                minElem = INT_MAX;
            }
        }
    }

    int top() { 
        if(!st.empty()){
            if(st.top()<minElem){
                return minElem;
            }
            return st.top();
        }
        return -1;
    }

    int getMin() { if(!st.empty()) return minElem;
        return -1;
    }
};

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int q; cin >> q;

    MinStack s;

    while(q--) {
        string op;
        cin >> op;

        if(op == "push") {
            int x;
            cin >> x;
            s.push(x);
        }
        else if(op == "pop") {
            s.pop();
        }
        else if(op == "top") {
            cout << s.top() << "\n";
        }
        else if(op == "getMin") {
            cout << s.getMin() << "\n";
        }
    }

    return 0;
}