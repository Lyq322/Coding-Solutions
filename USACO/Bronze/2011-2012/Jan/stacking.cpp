#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

struct Point {
  int pos;
  int label;
};

int N, K;
Point a[50000];
map<int, int> values;

bool comp(Point a, Point b) {
  if (a.pos == b.pos) {
    return a.label > b.label;
  }
  return a.pos < b.pos;
}

int main() {
  cin >> N >> K;
  int l, r;
  for (int i = 0; i < K; i++) {
    cin >> l >> r;
    a[2*i].pos = l;
    a[2*i].label = 1;
    a[2*i+1].pos = r+1;
    a[2*i+1].label = -1;
  }
  sort(a, a + 2*K, comp);
  cout << endl;
  for (int i = 0; i < 2*K; i++) {
    cout << a[i].pos << ' ' << a[i].label << endl;
  }
  int haybales = 0;
  int previous = 1;
  for (int i = 0; i < 2*K; i++) {
    cout << "i " << i << endl;
    cout << "previous " << previous << endl;
    cout << "haybales " << haybales << endl;
    if (values.find(haybales) == values.end()) {
      values[haybales] = a[i].pos - previous;
    }
    else {
      values[haybales] += a[i].pos - previous;
    }
    haybales += a[i].label;
    previous = a[i].pos;
  }
  for (auto const &x : values) {
    cout << x.first << ":" << x.second << ' ';
  }
  cout << endl;
  values[0] += N - a[2*K-1].pos + 1;
  cout << a[2*K-1].pos << endl;
  for (auto const &x : values) {
    cout << x.first << ":" << x.second << ' ';
  }
  cout << endl;
  int t = 0;
  for (auto const &x : values) {
    cout << x.first << ":" << x.second << endl;
    t = t + x.second;
    cout << t << endl;
    if (t >= N / 2) {
      cout << x.first << endl;
      break;
    }
  }
}