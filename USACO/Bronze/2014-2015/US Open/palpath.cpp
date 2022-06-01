#include <iostream>
#include <set>

using namespace std;

int n;
char grid[19][19];
set<string> temp;
set<string> palindrome;
int ans = 0;

void dfs1(int x, int y, string path) {
  if (x == 1 && y == 1) {
    temp.insert(path);
  }
  int a, b;
  a = x - 1;
  b = y;
  if (a >= 1) {
    dfs1(a, b, path + grid[a][b]);
  }
  a = x;
  b = y - 1;
  if (b >= 1) {
    dfs1(a, b, path + grid[a][b]);
  }
}

void dfs2(int x, int y, string path) {
  if (x == n && y == n) {
    if (temp.find(path) != temp.end() && palindrome.find(path) == palindrome.end()) {
      ans++;
      palindrome.insert(path);
    }
  }
  int a, b;
  a = x + 1;
  b = y;
  if (a <= n) {
    dfs2(a, b, path + grid[a][b]);
  }
  a = x;
  b = y + 1;
  if (b <= n) {
    dfs2(a, b, path + grid[a][b]);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> grid[i][j];
    }
  }
  int i = 1, j = n;
  while (j >= 1 && i <= n) {
    temp.clear();
    dfs1(i, j, string(1, grid[i][j]));
    dfs2(i, j, string(1, grid[i][j]));
    i++;
    j--;
  }
  cout << ans << endl;
}