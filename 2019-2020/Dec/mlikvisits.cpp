#include <iostream>
#include <vector>

using namespace std;

int n, m;
int tree[100000];
vector<vector<int>> paths;
bool visited[100000];
int r = 0;
int regions[100000];

void ff(int pos, int color) {
  regions[pos] = r;
  for (int i = 0; i < paths[pos].size(); i++) {
    int next = paths[pos][i];
    if (!visited[next] && tree[next] == color) {
      visited[next] = true;
      ff(next, color);
    }
  }
}

int main() {
  cin >> n >> m;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'H') {
      tree[i] = 0;
    }
    else {
      tree[i] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    paths.push_back({});
  }
  int a, b;
  for (int i = 0; i < n - 1; i++) {
    cin >> a >> b;
    paths[a - 1].push_back(b - 1);
    paths[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < n; i++) {
    visited[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      visited[i] = true;
      ff(i, tree[i]);
      r++;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << regions[i] << ' ';
  }
  cout << endl;
  char c;
  int t;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    if (c == 'H') {
      t = 0;
    }
    else {
      t = 1;
    }
    a--;
    b--;
    if (tree[a] != tree[b]) {
      cout << 1;
    }
    else if (tree[a] == t) {
      cout << 1;
    }
    else if (regions[a] != regions[b]) {
      cout << 1;
    }
    else {
      cout << 0;
    }
  }
  cout << endl;
} 