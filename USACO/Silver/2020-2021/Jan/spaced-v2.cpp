#include <iostream>

using namespace std;
typedef long long ll;

int n;
int points[1000][1000];

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> points[i][j];
    }
  }
  ll h = 0;
  for (int i = 0; i < n; i++) {
    int a = 0;
    int b = 0;
    for (int j = 0; j < n; j++) {
      if (j % 2 == 0) {
        a += points[i][j];
      }
      else {
        b += points[i][j];
      }
    }
    cout << a << ' ' << b << endl;
    h += max(a, b);
  }
  ll v = 0;
  for (int j = 0; j < n; j++) {
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        a += points[i][j];
      }
      else {
        b += points[i][j];
      }
    }
    cout << a << ' ' << b << endl;
    v += max(a, b);
  }
  cout << max(h, v) << endl;
} 