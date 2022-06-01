#include <iostream>
#include <vector>
#include <set>
#include <stack>

using namespace std;
typedef long long ll;

ll t, n, m;
vector<vector<ll>> path;
int visited[100000];

void dfs(ll pos, set<ll> & v) {
  for (ll i = 0; i < path[pos].size(); i++) {
    ll next = path[pos][i];
    if (visited[next] == 0) {
      v.insert(next);
      visited[next] = 1;
      dfs(next, v);
    }
  }
}

pair<ll, ll> calculate(ll i, set<ll> &fw, set<ll> &bw) {
  auto it = fw.lower_bound(i);
  auto it2 = bw.lower_bound(i);
  ll minimum, minimum2;
  if (it == fw.end()) {
    minimum = i - *prev(it);
  }
  else if (it == fw.begin()) {
    minimum = *it - i;
  }
  else {
    minimum = min(i - *prev(it), *it - i);
  }
  if (it2 == bw.end()) {
    minimum2 = i - *prev(it2);
  }
  else if (it2 == bw.begin()) {
    minimum2 = *it2 - i;
  }
  else {
    minimum2 = min(i - *prev(it2), *it2 - i);
  }
  return {minimum, minimum2};
}

void solve() {
  cin >> n >> m;
  ll a, b;
  path.clear();
  for (ll i = 0; i < n; i++) {
    path.push_back({});
    visited[i] = 0;
  }
  for (ll i = 0; i < m; i++) {
    cin >> a >> b;
    path[a - 1].push_back(b - 1);
    path[b - 1].push_back(a - 1);
  }
  set<ll> fw;
  set<ll> bw;
  ll front_arr[100000];
  ll back_arr[100000];
  fw.insert(0);
  bw.insert(n - 1);
  dfs(0, fw);
  for (ll i = 0; i < n; i++) {
    visited[i] = 0;
  }
  dfs(n - 1, bw);
  for (ll i = 0; i < n; i++) {
    visited[i] = 0;
  }
  cout << endl;
  calculate(0, fw, bw);
  for (ll i = 0; i < n; i++) {
    if (visited[i] == 0) {
      vector<ll> been;
      visited[i] = 1;
      stack<ll> s;
      s.push(i);
      been.push_back(i);
      ll minimum1 = -1;
      ll minimum2 = -1;
      while (!s.empty()) {
        ll p = s.top();
        s.pop();
        pair<ll, ll> pii = calculate(p, fw, bw);
        if (minimum1 == -1 || minimum1 > pii.first) {
          minimum1 = pii.first;
        }
        if (minimum2 == -1 || minimum2 > pii.second) {
          minimum2 = pii.second;
        }
        for (ll j = 0; j < path[p].size(); j++) {
          ll next = path[p][j];
          if (visited[next] == 0) {
            visited[next] = 1;
            s.push(next);
            been.push_back(next);
          }
        }
      }
      for (ll j = 0; j < been.size(); j++) {
        front_arr[been[j]] = minimum1;
        back_arr[been[j]] = minimum2;
      }
    }
  }
  ll ans = -1;
  for (ll i = 0; i < n; i++) {
    ll distance = front_arr[i] * front_arr[i] + back_arr[i] * back_arr[i];
    if (ans == -1 || distance < ans) {
      ans = distance;
    }
  }
  cout << ans << endl;
}

int main() {
  cin >> t;
  for (ll i = 0; i < t; i++) {
    solve();
  }
} 