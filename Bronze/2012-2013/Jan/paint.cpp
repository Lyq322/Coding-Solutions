#include <iostream>
#include <algorithm>

using namespace std;

struct Point{
  int pos;
  int label;
};

bool comp(Point x, Point y) {
  if (x.pos != y.pos) {
    return x.pos < y.pos;
  }
  if (x.label != y.label) {
    return x.label > y.label;
  }
  return x.pos < y.pos;
}

int main() {
  int N;
  cin >> N;
  string direction;
  int length;
  int a = 0;
  int b = 0;
  int c;
  Point intervals[2 * N];
  for (int i = 0; i < N; i++) {
    cin >> length >> direction; 
    c = a;
    if (direction == "L") {
      a = a - length;
      intervals[b].pos = a;
      intervals[b].label = 1;
      intervals[b + 1].pos = c;
      intervals[b + 1].label = -1;
      b = b + 2;
    }
    else {
      a = a + length;
      intervals[b].pos = c;
      intervals[b].label = 1;
      intervals[b + 1].pos = a;
      intervals[b + 1].label = -1;
      b = b + 2;
      }
  }
  sort(intervals, intervals + 2 * N, comp);
  int layers = 0;
  int previous;
  int L, R;
  int ans = 0;
  for (int k = 0; k < 2 * N; k++) {
    previous = layers;
    layers = layers + intervals[k].label;
    if (layers >= 2 && previous < 2) {
      L = intervals[k].pos;
    }
    else if (layers < 2 && previous >= 2) {
      R = intervals[k].pos;
      ans = ans + R - L;
    }
  }
  cout << ans << '\n';
}