#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int n;
pii cows[100000];
int minimum[100000];
int maximum[100000];

bool comp(pii a, pii b) {
  if (a.first == b.first) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> cows[i].first >> cows[i].second;
  }
  sort(cows, cows + n, comp);
  int m = cows[n - 1].second;
  for (int i = n - 1; i > -1; i--) {
    if (m > cows[i].second) {
      m = cows[i].second;
    }
    minimum[i] = m;
  }
  m = cows[0].second;
  for (int i = 0; i < n; i++) {
    m = max(m, cows[i].second);
    maximum[i] = m;
  }
  for (int i = 0; i < n; i++) {
    cout << minimum[i] << ' ' << maximum[i] << endl;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (cows[i].second <= minimum[i] && cows[i].second >= maximum[i]) {
      ans++;
    }
  }
  cout << ans << endl;
} 