#include <iostream>
#include <algorithm>

using namespace std;

struct Cow {
  int p;
  int b;
};

int N;
Cow cows[100000];

bool comp(Cow a, Cow b) {
  return a.p < b.p;
}

int main() {
  cin >> N;
  int pos;
  char breed;
  for (int i = 0; i < N; i++) {
    cin >> pos >> breed;
    cows[i].p = pos;
    if (breed == 'G') {
      cows[i].b = 1;
    }
    else {
      cows[i].b = -1;
    }
  }
  sort(cows, cows + N, comp);
  int i = 0;
  int start, finish;
  int best = 0;
  while (i < N) {
    while (cows[i].b == -1) {
      i++;
    }
    start = i;
    if (i >= N) {
      break;
    }
    while (cows[i].b == 1) {
      i++;
    }
    finish = i - 1;
    best = max(best, cows[finish].p - cows[start].p);
  }
  i = 0;
  while (i < N) {
    while (cows[i].b == 1) {
      i++;
    }
    start = i;
    if (i >= N) {
      break;
    }
    while (cows[i].b == -1) {
      i++;
    }
    finish = i - 1;
    best = max(best, cows[finish].p - cows[start].p);
  }
  int t = 0;
  int a[N];
  for (int i = 0; i < N; i++) {
    t = t + cows[i].b;
    a[i] = t;
  }
  int s[2*N+1];
  int f[2*N+1];
  for (int i = 0; i < 2 * N + 1; i++) {
    s[i] = -1;
    f[i] = -1;
  }
  s[N] = 0;
  for (int i = 0; i < N; i++) {
    if (s[a[i]+N] == -1) {
      s[a[i]+N] = i+1;
    }
    else {
      f[a[i]+N] = i;
    }
  }
  for (int i = 0; i < 2 * N + 1; i++) {
    if (s[i] != -1) {
      best = max(best, cows[f[i]].p - cows[s[i]].p);
    }
  }
  cout << best << endl;
}