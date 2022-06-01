#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int numbers[N][3];
  int a, b;
  int x, y, z;
  for (int i = 0; i < N; i++) {
    cin >> x >> y >> z;
    numbers[i][0] = x;
    numbers[i][1] = y;
    numbers[i][2] = z;
  }
  int c;
  bool d;
  bool e = true;
  for (int j = 1000; j < 10000; j++) {
    int num[4] = {j / 1000, (j / 100) % 10, (j / 10) % 10, j % 10};
    d = true;
    for (int m = 0; m < N; m++) {
      int k = numbers[m][0];
      bool f[4] = {true, true, true, true};
      bool g[4] = {true, true, true, true};
      a = 0;
      b = 0;
      int c[4] = {k / 1000, (k / 100) % 10, (k / 10) % 10, k % 10};
      for (int l = 0; l < 4; l++) {
        if (num[l] == c[l]) {
          f[l] = false;
          g[l] = false;
          a++;
        }
      }
      for (int m = 0; m < 4; m++) {
        if (f[m]) {
          for (int n = 0; n < 4; n++) {
            if (g[n]) {
              if (num[n] == c[m]) {
                f[m] = false;
                g[n] = false;
                b++;
                break;
              }
            }
          }
        }
      }
      if (a != numbers[m][1] || b != numbers[m][2]) {
        d = false;
        break;
      }
    }
    if (d) {
      cout << j << '\n';
      e = false;
      break;
    }
  }
  if (e) {
    cout << "NONE\n";
  }
}