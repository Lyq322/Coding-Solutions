#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Hay{
  int l;
  int w;
};

bool comp(Hay a, Hay b) {
  if (a.l == b.l) {
    return a.w < b.w;
  }
  return a.l < b.l;
}

void solve() {
  int N;
  int ans = 0;
  cin >> N;
  Hay hay[N];
  for (int i = 0; i < N; i++) {
    cin >> hay[i].l >> hay[i].w;
  }
  sort(hay, hay + N, comp);
  int a, h;
  for (int i = 0; i < pow(2, N); i++) {
    a = 0;
    h = 0;
    for (int j = 0; j < N; j++) {
      if ((i & (1 << j)) > 0) {
        if (a <= hay[j].w) {
          a = hay[j].w;
          h++;
        }
        else {
          break;
        }
      }
    }
    if (h > ans) {
      ans = h;
    }
  }
  cout << ans << endl;
}

int main() {
  solve();
}