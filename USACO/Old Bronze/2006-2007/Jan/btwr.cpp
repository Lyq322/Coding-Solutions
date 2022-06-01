#include <iostream>
#include <algorithm>

using namespace std;

int N;
int best = 0;

struct Hay{
  int l;
  int w;
};

bool comp(Hay x, Hay y) {
  if (x.l != y.l) {
    return x.l < y.l;
  }
  if (x.w != y.w) {
    return x.w < y.w;
  }
  return x.l < y.l;
}

void solve(int pos, Hay haybales[], int one, int index) {
  if (pos == N) {
    if (best < one) {
      best = one;
    }
    return;
  }
  if (one == 0) {
    solve(pos + 1, haybales, one, index);
    solve(pos + 1, haybales, one + 1, pos);
  }
  else {
    if (haybales[pos].w > haybales[index].w) {
      solve(pos + 1, haybales, one + 1, pos);
    }
    solve(pos + 1, haybales, one, index);
  }
}

int main() {
  cin >> N;
  int length, width;
  Hay haybales[N];
  for (int i = 0; i < N; i++) {
    cin >> length >> width;
    haybales[i].l = length;
    haybales[i].w = width;
  }
  sort(haybales, haybales + N, comp);
  /*
  for (int j = 0; j < N; j++) {
    cout << haybales[j].l << ' ' << haybales[j].w << '\n';
  }*/
  solve(0, haybales, 0, 0);
  cout << best << '\n';
}