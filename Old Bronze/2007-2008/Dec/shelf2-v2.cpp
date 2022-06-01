#include <iostream>
#include <cmath>

using namespace std;

void solve() {
  int N, B;
  int ans = -1;
  cin >> N >> B;
  int heights[N];
  for (int i = 0; i < N; i++) {
    cin >> heights[i];
  }
  for (int i = 0; i < pow(2,N); i++) {
    int h = 0;
    for (int j = 0; j < N; j++) {
      if ((i & (1 << j)) > 0) {
        h = h + heights[j];
      }
    }
    if (h >= B) {
      if (ans == -1 || h < ans) {
        ans = h;
      }
    }
  }
  cout << ans - B << endl;
}

int main() {
  solve();
}