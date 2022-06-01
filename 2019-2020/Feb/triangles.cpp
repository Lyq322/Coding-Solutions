#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Point {
  ll x;
  ll y;
  ll index;
};

ifstream fin;

pair<ll, ll> original[100000];
Point sortX[100000];
Point sortY[100000];
ll totalX[100000] = {0};
ll totalY[100000] = {0};
ll n;

bool comp1(Point a, Point b) {
  if (a.x == b.x) {
    return a.y < b.y;
  }
  return a.x < b.x;
}

bool comp2(Point a, Point b) {
  if (a.y == b.y) {
    return a.x < b.x;
  }
  return a.y < b.y;
}

int main() {
  fin.open("triangles.in");
  fin >> n;
  for (ll i = 0; i < n; i++) {
    fin >> original[i].first >> original[i].second;
    sortX[i].x = original[i].first;
    sortX[i].y = original[i].second;
    sortX[i].index = i;
    sortY[i].x = original[i].first;
    sortY[i].y = original[i].second;
    sortY[i].index = i;
  }
  sort(sortX, sortX + n, comp1);
  sort(sortY, sortY + n, comp2);
  ll i = 0;
  while (i < n) {
    ll L = 0;
    ll R = n;
    ll M;
    while (L < R) {
      M = (L + R) / 2;
      if (sortX[i].x >= sortX[M].x) {
        L = M + 1;
      }
      else {
        R = M;
      }
    }
    vector<Point> same;
    for (ll j = i; j < L; j++) {
      same.push_back(sortX[j]);
    }
    sort(same.begin(), same.end(), comp2);
    ll total = 0;
    for (ll j = 0; j < same.size(); j++) {
      total += same[j].y - same[0].y;
    }
    totalX[same[0].index] += total;
    for (ll j = 1; j < same.size(); j++) {
      total -= (same.size() - j) * (same[j].y - same[j - 1].y);
      totalX[same[j].index] += total;
    }
    total = 0;
    for (ll j = same.size() - 1; j > -1; j--) {
      total += same[same.size() - 1].y - same[j].y;
    }
    totalX[same[same.size() - 1].index] += total;
    for (ll j = same.size() - 2; j > -1; j--) {
      total -= (j + 1) * (same[j + 1].y - same[j].y);
      totalX[same[j].index] += total;
    }
    i = L;
  }
  i = 0;
  while (i < n) {
    ll L = 0;
    ll R = n;
    ll M;
    while (L < R) {
      M = (L + R) / 2;
      if (sortY[i].y >= sortY[M].y) {
        L = M + 1;
      }
      else {
        R = M;
      }
    }
    vector<Point> same;
    for (ll j = i; j < L; j++) {
      same.push_back(sortY[j]);
    }
    sort(same.begin(), same.end(), comp1);
    ll total = 0;
    for (ll j = 0; j < same.size(); j++) {
      total += same[j].x - same[0].x;
    }
    totalY[same[0].index] += total;
    for (ll j = 1; j < same.size(); j++) {
      total -= (same.size() - j) * (same[j].x - same[j - 1].x);
      totalY[same[j].index] += total;
    }
    total = 0;
    for (ll j = same.size() - 1; j > -1; j--) {
      total += same[same.size() - 1].x - same[j].x;
    }
    totalY[same[same.size() - 1].index] += total;
    for (ll j = same.size() - 2; j > -1; j--) {
      total -= (j + 1) * (same[j + 1].x - same[j].x);
      totalY[same[j].index] += total;
    }
    i = L;
  }
  ll area = 0;
  for (ll i = 0; i < n; i++) {
    area += totalX[i] * totalY[i];
    area = area % 1000000007;
  }
  cout << area << endl;
}