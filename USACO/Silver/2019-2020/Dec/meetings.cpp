#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;
typedef long long ll;

ifstream fin;
ofstream fout;

struct Cow {
  ll pos;
  ll weight;
  ll dir;
};


ll n, L;
Cow cows[50000];
ll dir_left[50000];
ll dir_right[50000];
ll total_weight = 0;
ll t = 0;
ll collision = 0;

ll ub(ll x, ll arr[], ll N) {
  ll L = 0;
  ll R = N;
  ll M;
  while (L < R) {
    M = (L + R) / 2;
    if (x >= arr[M]) {
      L = M + 1;
    }
    else {
      R = M;
    }
  }
  return L;
}

ll lb(ll x, ll arr[], ll N) {
  ll L = 0;
  ll R = N;
  ll M;
  while (L < R) {
    M = (L + R) / 2;
    if (x <= arr[M]) {
      R = M;
    }
    else {
      L = M + 1;
    }
  }
  return L;
}

bool comp(Cow a, Cow b) {
  if (a.pos != b.pos) {
    return a.pos < b.pos;
  }
  return a.dir > b.dir;
}

int main() {
  cin >> n >> L;
  ll l_cows = 0;
  ll r_cows = 0;
  for (ll i = 0; i < n; i++) {
    cin >> cows[i].weight >> cows[i].pos >> cows[i].dir;
    total_weight += cows[i].weight;
    if (cows[i].dir == 1) {
      dir_left[l_cows] = cows[i].pos;
      l_cows++;
    }
    else {
      dir_right[r_cows] = cows[i].pos;
      r_cows++;
    }
  }
  sort(cows, cows + n, comp);
  sort(dir_left, dir_left + l_cows);
  sort(dir_right, dir_right + r_cows);
  ll timel[50000];
  ll timer[50000];
  ll index1 = 0;
  ll index2 = 0;
  for (ll i = 0; i < n; i++) {
    if (cows[i].dir == 1) {
      timel[index1] = L - cows[i].pos;
      index1++;
    }
    else {
      timer[index2] = cows[i].pos;
      index2++;
    }
  }
  ll time[50000];
  index1 = 0;
  index2 = 0;
  for (ll i = 0; i < n; i++) {
    if (cows[i].dir == 1) {
      time[i] = timel[index1];
      index1++;
    }
    else {
      time[i] = timer[index2];
      index2++;
    }
  }
  ll weight = 0;
  ll l = 0, r = n - 1;
  while (weight * 2 < total_weight) {
    if (time[l] > time[r]) {
      weight += cows[r].weight;
      t = time[r];
      r--;
    }
    else {
      weight += cows[l].weight;
      t = time[l];
      l++;
    }
  }
  for (ll i = 0; i < n; i++) {
    if (cows[i].dir == 1) {
      l = cows[i].pos;
      r = l + t;
      if (r > L) {
        r = L;
      }
      collision += ub(r, dir_right, r_cows) - lb(l, dir_right, r_cows);
    }
    else {
      r = cows[i].pos;
      l = r - t;
      if (l < 0) {
        l = 0;
      }
      collision += ub(r, dir_left, l_cows) - lb(l, dir_left, l_cows);
    }
  }
  cout << collision / 2 << endl;
}