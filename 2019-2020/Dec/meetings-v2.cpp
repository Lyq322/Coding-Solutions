#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ifstream fin;
ofstream fout;

struct Point {
  ll pos;
  ll weight;
  ll dir;
};

ll n, l;
Point cows[50000];
vector<ll> cowsLeft;
vector<ll> cowsRight;
vector<ll> timeLeft;
vector<ll> timeRight;
vector<pair<ll, ll>> times;

bool comp(Point a, Point b) {
  return a.pos < b.pos;
}

int main() {
  fin.open("meetings.in");
  fin >> n >> l;
  ll totalWeight = 0;
  for (ll i = 0; i < n; i++) {
    fin >> cows[i].weight >> cows[i].pos >> cows[i].dir;
    if (cows[i].dir == -1) {
      cowsLeft.push_back(cows[i].pos);
    }
    else {
      cowsRight.push_back(cows[i].pos);
    }
    totalWeight += cows[i].weight;
  }
  sort(cows, cows + n, comp);
  for (int i = 0; i < n; i++) {
    if (cows[i].dir == -1) {
      timeLeft.push_back(cows[i].pos);
    }
    else {
      timeRight.push_back(l - cows[i].pos);
    }
  }
  for (int i = 0; i < timeLeft.size(); i++) {
    times.push_back({timeLeft[i], cows[i].weight});
  }
  for (int i = 0; i < timeRight.size(); i++) {
    times.push_back({timeRight[i], cows[i + timeLeft.size()].weight});
  }
  sort(times.begin(), times.end());
  ll i = 0;
  ll w = 0;
  ll t;
  for (int i = 0; i < n; i++) {
    w += times[i].second;
    if (2 * w >= totalWeight) {
      t = times[i].first;
      break;
    }
  }
  sort(cowsLeft.begin(), cowsLeft.end());
  sort(cowsRight.begin(), cowsRight.end());
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (cows[i].dir == -1) {
      ll right = cows[i].pos;
      ll left = cows[i].pos - 2 * t;
      int s = lower_bound(cowsRight.begin(), cowsRight.end(), left) - cowsRight.begin();
      int f = upper_bound(cowsRight.begin(), cowsRight.end(), right) - cowsRight.begin();
      ans += f - s;
    }
  }
  cout << ans << endl;
}