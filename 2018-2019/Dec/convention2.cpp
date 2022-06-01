#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Cow {
  int p;
  int t;
  int s;
};

int N;
Cow a[100000];
map<int, int> wait;
map<int, int> wt;
int ans = 0;

bool comp(Cow x, Cow y) {
  if (x.p == y.p) {
    return x.s < y.s;
  }
  return x.p < y.p;
}

int main() {
  cin >> N;
  int b, c;
  for (int i = 0; i < N; i++) {
    cin >> b >> c;
    a[i].p = b;
    a[i].t = c;
    a[i].s = i;
  }
  sort(a, a + N, comp);
  int cur = 0;
  int previous = 0;
  int front;
  int t;
  for (int i = 0; i < N; i++) {
    t = a[i].p;
    if (cur <= a[i].p - previous) {
      cur = 0;
    }
    else {
      cur = cur - (a[i].p - previous);
    }
    wait[a[i].s] = a[i].t;
    wt[a[i].s] = t;
    if (cur == 0) {
      front = wait.begin() -> second;
      wait.erase(wait.begin() -> first);
      ans = max(ans, t - wt.begin() -> second);
      wt.erase(wt.begin() -> first);
      cur = front;
    }
    previous = a[i].p;
    while (wait.size() != 0 && cur <= a[i+1].p - previous) {
      t = t + cur;
      previous = previous + cur;
      cur = 0;
      front = wait.begin() -> second;
      wait.erase(wait.begin() -> first);
      ans = max(ans, t - wt.begin() -> second);
      wt.erase(wt.begin() -> first);
      cur = front;
    }
  }
  cout << ans << endl;
}