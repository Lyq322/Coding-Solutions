#include <iostream>
#include <string>

using namespace std;

int main() {
  int M, F;
  cin >> M >> F;
  string bulls[M];
  string cows[F];
  for (int i = 0; i < M; i++) {
    cin >> bulls[i];
  }
  for (int j = 0; j < F; j++) {
    cin >> cows[j];
  }
  int a, b, c;
  bool child;
  int ans[M][F];
  for (int k = 0; k < M; k++) {
    b = k;
    for (int l = 0; l < F; l++) {
      c = l;
      a = 0;
      for (int m = 0; m < M; m++) {
        if (m != b) {
          child = true;
          for (int o = 0; o < 25; o++) {
            if (bulls[b].at(o) != bulls[m].at(o) && cows[c].at(o) != bulls[m].at(o)) {
              child = false;
              break;
            }
          }
          if (child) {
            a++;
          }
        }
      }
      for (int n = 0; n < F; n++) {
        if (n != c) {
          child = true;
          for (int p = 0; p < 25; p++) {
            if (bulls[b].at(p) != cows[n].at(p) && cows[c].at(p) != cows[n].at(p)) {
              child = false;
              break;
            }
          }
          if (child) {
            a++;
          }
        }
      }
      ans[k][l] = a;
    }
  }
  for (int q = 0; q < M; q++) {
    for (int r = 0; r < F; r++) {
      cout << ans[q][r] << ' ';
    }
    cout << '\n';
  }
}