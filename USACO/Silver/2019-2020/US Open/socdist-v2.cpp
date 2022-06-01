#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ifstream fin;
ofstream fout;

int n, m;
pii line[100000];
set<pii> start_points;

bool check(ll d) {
  ll c = 1;
  ll start = line[0].first;
  for (int i = 0; i < m; i++) {
    if (start + d < line[i].first) {
      start = line[i].first;
      c++;
    }
    while (start + d <= line[i].second) {
      start += d;
      c++;
    }
    if (c >= n) {
      return true;
    }
  }
  return false;
}

int main() {
  fin.open("socdist.in");
  fout.open("socdist.out");
  fin >> n >> m;
  for (int i = 0; i < m; i++) {
    fin >> line[i].first >> line[i].second;
    start_points.insert({line[i].first, line[i].second});
  }
  sort(line, line + m);
  ll l = 1;
  ll r = 1e18 + 1;
  while (l < r) {
    ll middle = l + (r - l + 1) / 2;
    if (check(middle)) {
      l = middle;
    }
    else {
      r = middle - 1;
    }
  }
  fout << l << endl;
} 