#include <iostream>
 
using namespace std;
 
int n, q;
int grid[1010][1010];
int ps[1010][1010];
 
int cal_ps(int a, int b, int c, int d) {
  return ps[c][d] - ps[c][b - 1] - ps[a - 1][d] + ps[a - 1][b - 1];
}
 
int main() {
  cin >> n >> q;
  char c;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> c;
      if (c == '.') {
        grid[i + 1][j + 1] = 0;
      }
      else {
        grid[i + 1][j + 1] = 1;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      ps[i][j] = grid[i][j] + ps[i][j - 1] + ps[i - 1][j] - ps[i - 1][j - 1];
    }
  }
  int a, b, d, e;
  int ans;
  for (int i = 0; i < q; i++) {
    cin >> a >> b >> d >> e;
    if (a >= d && b >= e) {
      ans = cal_ps(d, e, a, b);
    }
    else if (a <= d && b <= e) {
      ans = cal_ps(a, b, d, e);
    }
    else if (a > d && b < e) {
      ans = cal_ps(d, b, a, e);
    }
    else {
      ans = cal_ps(a, e, d, b);
    }
    cout << ans << endl;
  }
} 