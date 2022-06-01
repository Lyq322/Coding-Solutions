#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, L;
int *knots;
int *rope;
vector<int> points;

bool test(int pos) {
  int left = pos;
  int right = pos;
  while (left >= 0 && right <= 2 * L) {
    //cout << "left " << left << ' ' << rope[left] << endl;
    //cout << "right " << right << ' ' << rope[right] << endl;
    if (rope[left] != rope[right]) {
      return false;
    }
    else {
      left--;
      right++;
    }
  }
  return true;
}

int main() {
  cin >> N >> L;
  knots = new int[N];
  rope = new int[2 * L];
  int ans = 0;
  for (int i = 0; i < 2 * L; i++) {
    rope[i] = 0;
  }
  for (int i = 0; i < N; i++) {
    cin >> knots[i];
    rope[2 * knots[i]] = 1;
    if (knots[i] != 0 && knots[i] != L) {
      points.push_back(knots[i] * 2);
    }
  }
  sort(knots, knots + N);
  for (int i = 0; i < N - 1; i++) {
    if (rope[knots[i] + knots[i + 1]] != 1) {
      points.push_back(knots[i] + knots[i + 1]);
    }
  }
  for (int i = 0; i < points.size(); i++) {
    //cout << '\n';
    //cout << "point " << points[i] << endl;
    bool fold = test(points[i]);
    if (fold) {
      ans++;
    }
  }
  cout << ans << endl;
}