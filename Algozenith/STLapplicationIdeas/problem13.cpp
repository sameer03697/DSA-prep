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

//direction Mod
int dMd = 4;

struct Position
{
  /* Diections */
  //0--> North
  //1--> East
  //2--> South
  //3--> West
  int x;
  int y;
  int direction;
  void rotateL(){
    direction = (direction - 1)%dMd;
    if(direction<0)
      direction += dMd;
  }
  void rotateR(){
    direction = (direction + 1) % dMd;
    if(direction<0)
      direction += dMd;
  }
  void walk(){
    if(direction==0){
      y = y + 1;
    }else if(direction==1){
      x = x + 1;
    }else if (direction==2){
      y = y - 1;
    }else if(direction==3){
      x = x - 1;
    }else {
      cout << "error" << endl;
    }
  }

  void print(){
    cout << "position of P:"
         << "(" << x << "," << y << ")"
         << "Direction:" << direction << endl;
  }

  void addPosition (Position diff){
    if(direction==0){
      x = x + diff.x;
      y = y + diff.y;
    }else if(direction==1){
      x = x+diff.y;
      y = y - diff.x;
    }else if(direction==2){
      x = x- diff.x;
      y = y - diff.y;
    }else if(direction==3){
      x = x-diff.y;
      y = y+diff.x;
    }
    direction = (direction + diff.direction) % dMd;
    if(direction<0)
      direction += dMd;
  }
};

void solve(){
  int n;
  cin >> n;
  Position P;
  P.x = 0;
  P.y = 0;
  P.direction = 0;

  for (int i = 0; i < n;i++){
    char cc;
    cin >> cc;
    // cout << cc;

    if(cc=='W'){
      P.walk();
    }
    if(cc=='L'){
      P.rotateL();
    }
    if(cc=='R'){
      P.rotateR();
    }
  }
  // P.print();
  if(P.x==0 && P.y==0){
    cout << "YES" << endl;
    return;
  }
  if(P.direction==0){
    cout << "NO" << endl;
    return;
  }

  
  Position initial;
  initial.x = 0;
  initial.y = 0;
  initial.direction = 0;
  initial.addPosition(P);
  // initial.print();
  initial.addPosition(P);
  // initial.print();
  initial.addPosition(P);
  // initial.print();
  initial.addPosition(P);
  // initial.print();

  if(initial.x==0 && initial.y==0){
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _t;cin>> _t; while(_t--)
    solve();
}