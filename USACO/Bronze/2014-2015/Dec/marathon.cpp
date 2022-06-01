#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int N;
pii* points;
int* d;
int total = 0;
int ans = -1;

int distance(int x1, int y1, int x2, int y2) {
  return abs(x1-x2) + abs(y1-y2);
}

int main() {
  cin >> N;
  points = new pii[N];
  d = new int[N - 2];
  for (int i = 0; i < N; i++) {
    cin >> points[i].first;
    cin >> points[i].second;
  }
  for (int i = 0; i < N - 1; i++) {
    if (i < N - 2) {
      d[i] = distance(points[i].first, points[i].second, points[i + 2].first, points[i + 2].second);
    }
    total = total + distance(points[i].first, points[i].second, points[i + 1].first, points[i + 1].second);
  }
  int a;
  for (int i = 0; i < N - 2; i++) {
    a = total - distance(points[i].first, points[i].second, points[i + 1].first,points[i + 1].second) - distance(points[i + 1].first, points[i + 1].second, points[i + 2].first, points[i + 2].second) + d[i];
    if (ans == -1 || ans > a) {
      ans = a;
    }
  }
  cout << ans << endl;
}