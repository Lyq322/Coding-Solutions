#include <iostream>
#include <queue>

using namespace std;

int k, n, m;
int cows[100];
int cities[1001][1001] = {{0}};
int visited[1001] = {0};
int all_visited[1001] = {0};
queue<int> path;
int ans = 0;

int main() {
  cin >> k >> n >> m;
  for (int i = 0; i < k; i++) {
    cin >> cows[i];
  }
  int a, b;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    cities[a][b] = 1;
  }
  for (int i = 0; i < k; i++) {
    int cow = cows[i];
    cout << "cow " << cow << endl;
    path.push(cow);
    visited[cow] = 1;
    while (!path.empty()) {
      int pos = path.front();
      cout << "pos " << pos << endl;
      path.pop();
      for (int j = 1; j <= n; j++) {
        if (cities[pos][j] == 1 && visited[j] == 0) {
          visited[j] = 1;
          path.push(j);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == 1) {
        all_visited[i]++;
        visited[i] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (all_visited[i] == k) {
      ans++;
    }
  }
  cout << ans << endl;
}