#include <iostream>
#include <stack>

using namespace std;

int n;
char map[100][100][100];
int visited[100][100][100];
int di[6] = {0, 0, 0, 0, 1, -1};
int dj[6] = {-1, 1, 0, 0, 0, 0};
int dk[6] = {0, 0, 1, -1, 0, 0};
int ans = 0;

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        cin >> map[i][j][k];
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        if (visited[i][j][k] == false && map[i][j][k] == '*') {
          ans++;
          visited[i][j][k] = true;
          stack<int> sx;
          stack<int> sy;
          stack<int> sz;
          sx.push(i);
          sy.push(j);
          sz.push(k);
          while (!sx.empty()) {
            int x = sx.top();
            int y = sy.top();
            int z = sz.top();
            sx.pop();
            sy.pop();
            sz.pop();
            for (int i = 0; i < 6; i++) {
              int a = di[i] + x;
              int b = dj[i] + y;
              int c = dk[i] + z;
              if (a >= 0 && b >= 0 && c >= 0 && a < n && b < n && c < n) {
                if (!visited[a][b][c] && map[a][b][c] == '*') {
                  visited[a][b][c] = true;
                  sx.push(a);
                  sy.push(b);
                  sz.push(c);
                }
              }
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
} 