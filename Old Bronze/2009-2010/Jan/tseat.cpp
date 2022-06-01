#include <iostream>
#include <algorithm>

using namespace std;

struct Seat {
  int d;
  int x;
  int y;
};

bool comp(Seat a, Seat b) {
  if (a.d != b.d) {
    return a.d < b.d;
  }
  if (a.y != b.y) {
    return a.y > b.y;
  }
  return a.x < b.x;
}

int distance(Seat center, Seat point) {
  return (center.x - point.x) * (center.x - point.x) + (center.y - point.y) * (center.y - point.y);
}
int main() {
  int W, R;
  cin >> W >> R;
  int N = W * R;
  Seat center = {0, (W + 1) / 2 - 1, R - 1};
  Seat s[N];
  int a = 0;
  int b = 0;
  for (int i = 0; i < N; i++) {
    s[i].x = a;
    s[i].y = b;
    s[i].d = distance(center, s[i]);
    //cout << '[' << s[i].x << ' ' << s[i].y << ' ' << s[i].d << "] ";
    a++;
    if (a == W) {
      b++;
      a = 0;
      //cout << '\n';
    }
  }
  //cout << '\n' << '\n';
  sort(s, s + N, comp);
  
  a = 0;
  /*
  for (int j = 0; j < N; j++) {
    cout << '[' << s[j].x << ' ' << s[j].y << ' ' << s[j].d << "] ";
    a++;
    if (a == W) {
      cout <<'\n';
      a = 0;
    }
  }
  cout << '\n';
  */
  int table[R][W];
  for (int k = 0; k < N; k++) {
    table[s[k].y][s[k].x] = k + 1;
  }
  for (int l = 0; l < R; l++) {
    for (int m = 0; m < W; m++) {
      cout << table[l][m] << ' ';
    }
    cout << '\n';
  }
  
}