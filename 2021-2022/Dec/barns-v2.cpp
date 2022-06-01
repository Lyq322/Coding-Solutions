#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef long long ll;

int t, n, m;

int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    //cout << "new case\n";
    cin >> n >> m;
    vector<vector<int>> adj;
    int visited[100000] = {0};
    ll distance[100000] = {0};
    ll distance2[100000] = {0};
    for (int j = 0; j < n; j++) {
      adj.push_back({});
    }
    int a, b;
    for (int j = 0; j < m; j++) {
      cin >> a >> b;
      a--;
      b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    queue<ll> q;
    q.push(0);
    vector<ll> reach;
    vector<ll> reach2;
    reach.push_back(0);
    visited[0] = 1;
    while (!q.empty()) {
      int pos = q.front();
      q.pop();
      for (int j = 0; j < adj[pos].size(); j++) {
        int next = adj[pos][j];
        if (visited[next] == 0) {
          visited[next] = 1;
          q.push(next);
          reach.push_back(next);
        }
      }
    }
    q.push(n - 1);
    reach2.push_back(n - 1);
    for (int k = 0; k < n; k++) {
      visited[i] = 0;
    }
    visited[n - 1] = 1;
    while (!q.empty()) {
      int pos = q.front();
      q.pop();
      for (int j = 0; j < adj[pos].size(); j++) {
        int next = adj[pos][j];
        if (visited[next] == 0) {
          visited[next] = 1;
          q.push(next);
          reach2.push_back(next);
        }
      }
    }
    sort(reach.begin(), reach.end());
    sort(reach2.begin(), reach2.end());
    for (int k = 0; k < n; k++) {
      auto it = lower_bound(reach.begin(), reach.end(), k);
      int d;
      if (it == reach.begin()) {
        d = reach[0] - k;
      }
      else if (it == reach.end()) {
        d = k - reach[reach.size() - 1];
      }
      else {
        d = min(*it - 1, k - *prev(it));
      }
      d = d * d;
      distance[k] = d;
    }
    for (int k = 0; k < n; k++) {
      auto it = lower_bound(reach2.begin(), reach2.end(), k);
      int d;
      if (it == reach2.begin()) {
        d = reach2[0] - k;
      }
      else if (it == reach2.end()) {
        d = k - reach2[reach2.size() - 1];
      }
      else {
        d = min(*it - 1, k - *prev(it));
      }
      d = d * d;
      distance2[k] = d;
    }
    for (int k = 0; k < n; k++) {
      visited[k] = 0;
    }
    int ans = -1;
    for (int j = 0; j < n; j++) {
      if (visited[j] == 0) {
        queue<int> q;
        q.push(j);
        int m = j;
        vector<int> add;
        visited[j] = 1;
        add.push_back(j);
        while (!q.empty()) {
          int pos = q.front();
          q.pop();
          if (pos == n - 1) {
            break;
          }
          for (int j = 0; j < adj[pos].size(); j++) {
            int next = adj[pos][j];
            if (visited[next] == 0) {
              visited[next] = 1;
              q.push(next);
              m = max(m, next);
              add.push_back(next);
            }
          }
        }
        ll min_f = -1;
        ll min_b = -1;
        for (int k = 0; k < add.size(); k++) {
          if (min_f == -1 || min_f > distance[add[k]]) {
            min_f = distance[add[k]];
          }
          if (min_b == -1 || min_b > distance2[add[k]]) {
            min_b = distance2[add[k]];
          }
        }
        if (ans == -1 || ans > min_f + min_b) {
          ans = min_f + min_b;
        }
      }
    }
    cout << ans << endl;
  }
} 