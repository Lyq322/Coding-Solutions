#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
  int pos;
  int p;
};

bool comp(Point a, Point b) {
  if (a.pos == b.pos) {
    return a.p > b.p;
  }
  return a.pos < b.pos;
}

int N, X, Y, Z;
Point* temp;
int ans = 0;

int main() {
  cin >> N >> X >> Y >> Z;
  temp = new Point[2 * N];
  int a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    //cout << a << ' ' << b << endl;
    temp[2*i].pos = a;
    temp[2*i].p = 1;
    temp[2*i+1].pos = b;
    temp[2*i+1].p = -1;
  }
  sort(temp, temp + 2*N, comp);
  //for (int i = 0; i < N; i++) {
  //  cout << temp[2*i].pos << ' ' << temp[2*i].p << endl;
  //  cout << temp[2*i+1].pos << ' ' << temp[2*i+1].p << endl;
  //}
  int milk = X * N;
  for (int i = 0; i < 2*N; i++) {
    if (temp[i].p == 1) {
      milk = milk - X + Y;
    }
    else {
      milk = milk - Y + Z;
    }
    if (milk > ans) {
      ans = milk;
    }
  }
  cout << ans << endl;
}