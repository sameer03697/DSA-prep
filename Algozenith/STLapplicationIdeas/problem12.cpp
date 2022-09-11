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
int getVal(char c1, char op, char c2, int val){
    int v1, v2;
    if (c1 == '0'){
        v1 = 0;}
    else if(c1=='1'){
        v1 = 1;}else{
        throw invalid_argument("Invalid c1 received");
    }

    if(c2=='0'){
        v2 = 0;}
        else if(c2=='1'){
            v2 = 1;
        }else{
            throw invalid_argument("Invalid C2 received");
        }
    if(op=='&')
        return char('0' + (v1 & v2));
    if(op=='|')
        return char('0' + (v1 | v2));
    if(op=='^')
        return char('0' + (v1 ^ v2));
    throw invalid_argument("Invalid op received");
}
int eval(string s, int x){
    stack<char> st;
    for (int i = 0; i < s.length();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }else if(s[i]==')'){
            char c2 = st.top();
            st.pop();
            char operand = st.top();
            st.pop();
            char c1 = st.top();
            st.pop();
            st.pop();
            // cout << "value of arguements: " << c1 << c2 << operand << x << endl;
            char val = getVal(c1, operand, c2, x);
            st.push(val);
        } else {
            if (s[i]=='x')
                st.push(char('0' + x));
            else if (s[i]=='X')
                st.push(char('0' + 1 - x));
            else {
                st.push(s[i]);
            }
        }
    }
    if(st.size()>1)
        throw invalid_argument("stack not processed properly");
    return st.top() - '0';
}
void solve(){
    string s;
    cin >> s;
    int x = eval(s, 1);
    int y = eval(s, 0);
    if(x==y){
        cout << 0 << endl;
    }else{
        cout << 1 << endl;
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