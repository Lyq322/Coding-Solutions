#include <iostream>
#include <map>
#include <set>

using namespace std;

int N;
int pos[50000][2];
map<int, int> horizontal;
map<int, int> vertical;
int ans = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> pos[i][0] >> pos[i][1];
  }
  for (int i = 0; i < N; i++) {
    if (horizontal.find(pos[i][1]) == horizontal.end()) {
      horizontal[pos[i][1]] = 1;
    }
    else {
      horizontal[pos[i][1]]++;
    }
    if (vertical.find(pos[i][0]) == vertical.end()) {
      vertical[pos[i][0]] = 1;
    }
    else {
      vertical[pos[i][0]]++;
    }
  }
  if (vertical.size() <= 3 || horizontal.size() <= 3) {
    cout << 1 << endl;
  }
  else {
    int index1, index2;
    int m1 = 0;
    int m2 = 0;
    for (auto const &x : horizontal) {
      if (x.second > m1) {
        m1 = x.second;
        index1 = x.first;
      }
    }
    for (auto const &x : vertical) {
      if (x.second > m2) {
        m2 = x.second;
        index2 = x.first;
      }
    }
    set<int> h;
    set<int> v;
    for (int i = 0; i < N; i++) {
      if (pos[i][1] != index1) {
        h.insert(pos[i][0]);
      }
      if (pos[i][0] != index2) {
        v.insert(pos[i][1]);
      }
    }
    if (h.size() <= 2 || v.size() <= 2) {
      cout << 1 << endl;
    }
    else {
      cout << 0 << endl;
    }
  }
}