#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Point {
  int pos;
  int id;
  int label;
};

int N;
Point lg[200000];
map<int, int> alone;
set<int> onduty;

bool comp(Point a, Point b) {
  if (a.pos == b.pos) {
    return a.label > b.label;
  }
  return a.pos < b.pos;
}

int main() {
  cin >> N; 
  for (int i = 0; i < N; i++) {
    alone[i] = 0;
    cin >> lg[2*i].pos >> lg[2*i+1].pos;
    lg[2*i].label = 1;
    lg[2*i].id = i;
    lg[2*i+1].label = -1;
    lg[2*i+1].id = i;
  }
  sort(lg, lg+2*N, comp);
  int active = 0;
  int temp;
  int total = 0;
  int L;
  for (int i = 0; i < 2*N; i++) {
    temp = active;
    active = active + lg[i].label;
    if (temp == 0 && active > 0) {
      L = lg[i].pos;
    }
    else if (temp > 0 && active == 0) {
      total += lg[i].pos - L;
    }
  }
  int start;
  for (int i = 0; i < 2*N; i++) {
    int x = lg[i].id;
    if (onduty.size() == 1) {
      alone[*onduty.begin()] += lg[i].pos - start;
    }
    if (lg[i].label == -1) {
      onduty.erase(x);
    }
    else if (lg[i].label == 1) {
      onduty.insert(x);
    }
    start = lg[i].pos;
  }
  int a = -1;
  for (const auto& x : alone) {
    if (a == -1 || x.second < a) {
      a = x.second;
    }
  }
  cout << total - a << endl;
}