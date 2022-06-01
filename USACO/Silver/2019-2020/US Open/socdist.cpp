#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
  int x;
  int y;
};

int N, M;
Point* intervals;

bool comp(Point a, Point b) {
  return a.x < b.y;
}

bool distance(int d) {
  int c = 0;
  int start = -10000000;
  for (int i = 0; i < M; i++) {
    while (start + d <= intervals[i].y) {
      start = max(start + d, intervals[i].x);
      c++;
      if (c >= N) {
        return true;
      }
    }
    if (c >= N) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> N >> M;
  intervals = new Point[M];
  int a, b;
  for (int i = 0; i < M; i++) {
    cin >> a >> b;
    intervals[i].x = a;
    intervals[i].y = b;
  }
  sort(intervals, intervals + M, comp);
  int l = 1;
  int r = intervals[M - 1].y / (N - 1);
  int m;
  while (l <= r) {
    m = (l + r) / 2;
    if (distance(m)) {
      if (!distance(m + 1)) {
        break;
      }
      l = m + 1;
    }
    else {
      r = m - 1;
    }
  }
  cout << m << endl;
}