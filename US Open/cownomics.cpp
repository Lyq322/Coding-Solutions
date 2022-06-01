#include <iostream>

using namespace std;

int N, M;
char spotted[500][50];
char plain[500][50];
int ans = 0;

int tr(char a) {
  int n;
  if (a == 'A') {
    n = 0;
  }
  else if (a == 'C') {
    n = 1;
  }
  else if (a == 'G') {
    n = 2;
  }
  else if (a == 'T') {
    n = 3;
  }
  return n;
}

int translate(char a, char b, char c) {
  int n1 = tr(a);
  int n2 = tr(b);
  int n3 = tr(c);
  return 16 * n1 + 4 * n2 + n3;
}

int main() {
  cin >> N >> M;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> spotted[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> plain[i][j];
    }
  }
  for (int i = 0; i < M - 2; i++) {
    for (int j = i + 1; j < M - 1; j++) {
      for (int k = j + 1; k < M; k++) {
        int reverse[64] = {0};
        for (int l = 0; l < N; l++) {
          reverse[translate(spotted[l][i], spotted[l][j], spotted[l][k])] = 1;
        }
        bool b = true;
        for (int l = 0; l < N; l++) {
          if (reverse[translate(plain[l][i], plain[l][j], plain[l][k])] == 1) {
            b = false;
            break;
          }
        }
        if (b) {
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}