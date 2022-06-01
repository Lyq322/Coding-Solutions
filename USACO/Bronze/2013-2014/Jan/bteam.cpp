#include <iostream>
#include <algorithm>

using namespace std;

int skill[12];
int ans[12];
int mark[4] = {0};
int best = -1;

void solve(int pos) {
  if (pos == 12) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    for (int i = 0; i < 12; i++) {
      if (ans[i] == 1) {
        a = a + skill[i];
      }
      else if (ans[i] == 2) {
        b = b + skill[i];
      }
      else if (ans[i] == 3) {
        c = c + skill[i];
      }
      else {
        d = d + skill[i];
      }
    }
    int difference = max(max(a, b), max(c, d)) - min(min(a, b), min(c, d));
    if (difference < best || best == -1) {
      best = difference;
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    if (mark[i] < 3) {
      ans[pos] = i + 1;
      mark[i]++;
      solve(pos + 1);
      mark[i]--;
    }
  }
}

int main() {
  for (int i = 0; i < 12; i++) {
    cin >> skill[i];
  }
  int ans[12];
  solve(0);
  cout << best << '\n';
}