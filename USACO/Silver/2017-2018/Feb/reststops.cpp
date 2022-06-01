#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Store {
  int pos;
  int val;
};

int L, N, r_F, r_B;
Store stores[100000];
vector<Store> stops;
int ans = 0;

bool comp(Store a, Store b) {
  return a.pos < b.pos;
}

int main() {
  cin >> L >> N >> r_F >> r_B;
  for (int i = 0; i < N; i++) {
    cin >> stores[i].pos >> stores[i].val;
  }
  sort(stores, stores + N, comp);
  int max_val = 0;
  for (int i = N - 1; i > -1; i--) {
    if (stores[i].val > max_val) {
      stops.push_back(stores[i]);
      max_val = stores[i].val;
    }
  }
  int cur_pos = 0;
  for (int i = stops.size() - 1; i > -1; i--) {
    ans += (stops[i].pos - cur_pos) * stops[i].val * (r_F - r_B);
    cur_pos = stops[i].pos;
  }
  cout << ans << endl;
}