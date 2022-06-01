#include <iostream>
#include <cmath>

using namespace std;

int swap(int x) {
  if (x == 0) {
    return 1;
  }
  return 0;
}

void solve() {
  int bowl[20];
  for (int i = 0; i < 20; i++) {
    cin >> bowl[i];
  }
  int a[20];
  bool b;
  int flip;
  int ans = -1;
  for (int i = 0; i < pow(2,20); i++) {
    //cin.ignore();
    //cout << "i " << i << endl;
    for (int j = 0; j < 20; j++) {
      a[j] = bowl[j];
    }
    flip = 0;
    for (int j = 0; j < 20; j++) {
      if ((i & (1 << j)) > 0) {
        flip++;
        if (j == 0) {
          a[0] = swap(a[0]);
          a[1] = swap(a[1]);
        }
        else if (j == 19) {
          a[19] = swap(a[19]);
          a[18] = swap(a[18]);
        }
        else {
          a[j] = swap(a[j]);
          a[j + 1] = swap(a[j+1]);
          a[j - 1] = swap(a[j-1]);
        }
      }
    }
    /*
    for (int j = 0; j < 20; j++) {
      cout << a[j] << ' ';
    }
    cout << endl;*/
    b = true;
    for (int j = 0; j < 20; j++) {
      if (a[j] == 1) {
        b = false;
        break;
      }
    }
    if (b) {
      if (ans == -1 || flip < ans) {
        ans = flip;
      }
    }
  }
  cout << ans << endl;
}
int main() {
  solve();
}