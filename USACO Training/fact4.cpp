#include <iostream>

using namespace std;

int main() {
  int N;
  cin >> N;
  int ans = 1;
  if (N == 0) {
    cout << 1 << '\n';
  }
  else {
    for (int i = 1; i < N + 1; i++) {
      ans = ans * i;
    }
    cout << ans << '\n';
  }
}