#include <iostream>
#include <cmath>

using namespace std;

int *fj;
int *m;
int N;
int ans = 0;

bool close(int combination[], int password[]) {
  for (int i = 0; i < 3; i++) {
    if (abs(combination[i] - password[i]) > 2 && abs(combination[i] - password[i]) < N - 2) {
      return false;
    }
  }
  return true;
}

int main() {
  cin >> N;
  fj = new int [3];
  m = new int [3];
  cin >> fj[0];
  cin >> fj[1];
  cin >> fj[2];
  cin >> m[0];
  cin >> m[1];
  cin >> m[2];
  int combination[3];
  for (int i = 0; i < N; i++) {
    combination[0] = i + 1;
    for (int j = 0; j < N; j++) {
      combination[1] = j + 1;
      for (int k = 0; k < N; k++) {
        combination[2] = k + 1;
        if (close(combination, m) || close(combination, fj)) {
          //cout << combination[0] << ' ' << combination[1] << ' ' << combination[2] << endl;
          ans++;
        }
      }
    }
  }
  cout << ans << endl;
}