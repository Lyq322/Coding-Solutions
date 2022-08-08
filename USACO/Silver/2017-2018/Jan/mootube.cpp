#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, Q;
vector<vector<pair<int,int>>> adj_list;
bool visited[5000];
int dist;
int videos;

void dfs(int pos, int d) {
  for (int i = 0; i < adj_list[pos].size(); i++) {
    if (visited[adj_list[pos][i].first]) {
      continue;
    }
    else if (d != 0 && min(d, adj_list[pos][i].second) < dist) {
      continue;
    }
    else if (d == 0 && adj_list[pos][i].second < dist) {
      continue;
    }
    visited[adj_list[pos][i].first] = true;
    videos++;
    if (d == 0) {
      dfs(adj_list[pos][i].first, adj_list[pos][i].second);
    }
    else {
      dfs(adj_list[pos][i].first, min(d, adj_list[pos][i].second));
    }
    visited[adj_list[pos][i].first] = false;
  }
}

int main() {
  cin >> n >> Q;
  int p, q, r;
  for (int i = 0; i < n; i++) {
    adj_list.push_back({});
    visited[i] = false;
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> p >> q >> r;
    adj_list[p - 1].push_back({q - 1, r});
    adj_list[q - 1].push_back({p - 1, r});
  }
  int v;
  for (int i = 0; i < Q; i++) {
    cin >> dist >> v;
    v--;
    videos = 0;
    visited[v] = true;
    dfs(v, 0);
    visited[v] = false;
    cout << videos << endl;
  }
}