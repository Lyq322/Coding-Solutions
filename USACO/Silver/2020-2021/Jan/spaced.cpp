#include <iostream>
#include <stack>

using namespace std;
typedef pair<int, int> pii;

const int max_n = 1000;

int n;
int points[max_n][max_n];
int grid[max_n][max_n] = {{0}};
int p = 0;
int ans = 0;

void cal(int x, int y) {
  if (x == n && y == 0) {
    p = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        p += grid[i][j] * points[i][j];
      }
    }
    ans = max(ans, p);
    return;
  }
  if (x == 0) {
    grid[x][y] = 1;
    if (y + 1 == n) {
      cal(x + 1, 0);
    }
    else {
      cal(x, y + 1);
    }
    grid[x][y] = 0;
    if (y + 1 == n) {
      cal(x + 1, 0);
    }
    else {
      cal(x, y + 1);
    }
  }
  else {
    if (y == 0) {
      int count = 0;
      if (grid[x - 1][y] == 1) {
        count++;
      }
      if (grid[x - 1][y + 1] == 1) {
        count++;
      }
      if (count < 2) {
        grid[x][y] = 1;
        cal(x, y + 1);
        grid[x][y] = 0;
      }
      cal(x, y + 1);
    }
    else {
      int count = 0;
      if (grid[x - 1][y] == 1) {
        count++;
      }
      if (grid[x][y - 1] == 1) {
        count++;
      }
      if (grid[x - 1][y - 1] == 1) {
        count++;
      }
      if (count == 2) {
        if (y + 1 == n) {
          cal(x + 1, 0);
        }
        else {
          cal(x, y + 1);
        }
      } 
      else if (count == 1) {
        grid[x][y] = 1;
        if (y + 1 == n) {
          cal(x + 1, 0);
        }
        else {
          cal(x, y + 1);
        }
        grid[x][y] = 0;
      }
      else {
        return;
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> points[i][j];
    }
  }
  cal(0, 0);
  cout << ans << endl;
} 