#include <iostream>

using namespace std;

int n, k;
pair<int, int> cows[100000];

int main() {
  cin >> n >> k;
  int a, b;
  for (int i = 0; i < k; i++) {
    cin >> a >> b;
    cows[i] = {a - 1, b - 1};
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      bool shoot = true;
      for (int l = 0; l < k; l++) {
        int sub1 = abs(i - cows[l].first);
        int sub2 = abs(j - cows[l].second);
        if (sub1 != sub2 && sub1 != 0 && sub2 != 0) {
          shoot = false;
          break;
        }
      }
      if (shoot) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}