#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long double ll;

int n;
int friends[60000];
int speed[60000];

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
  if (a.first == b.first) {
    return a.second > b.second;
  }
  return a.first < b.first;
}

bool check(ll second) {
  vector<pair<ll, ll>> points;
  for (int i = 0; i < n; i++) {
    points.push_back({friends[i] - second * speed[i], 1});
    points.push_back({friends[i] + second * speed[i], -1});
  }
  sort(points.begin(), points.end(), comp);
  ll d = 0;
  for (int i = 0; i < 2 * n; i++) {
    d += points[i].second;
    if (d == n) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> friends[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> speed[i];
  }
  ll l = 0.0;
  ll r = 1e18;
  while (l <= r) {
    ll m = (l + r) * 0.5;
    if (check(m)) {
      r = m - 0.0000001;
    }
    else {
      l = m + 0.0000001;
    }
  }
  cout.precision(12);
  cout << l << endl;
} 