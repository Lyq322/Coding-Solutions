#include <iostream>

using namespace std;

int N;
int matrix[200][200];
int ans;
bool c = false;
int di[4] = {0, 1, 1, 1};
int dj[4] = {1, 0, 1, -1};

int main() {
  cin >> N;
  dj[3] = -1 + N;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> matrix[i][j];
    }
  }
  int a, b;
  int t;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      //cout << "i " << i << " j " << j << endl;
      a = i;
      b = j;
      for (int l = 0; l < 4; l++) {
        t = matrix[a][b];
        if (!c) {
          ans = t;
          c = true;
        }
        if (ans < t) {
          ans = t;
        }
        for (int k = 0; k < N - 1; k++) {
          a = (a + di[l]) % N;
          b = (b + dj[l]) % N;
          t = t + matrix[a][b];
          if (!c) {
            ans = t;
            c = true;
          }
          if (ans < t) {
            ans = t;
          }
        }
      }
    }
  }
  cout << ans << endl;
}