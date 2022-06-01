#include <iostream>

using namespace std;

int n;
int cows[50001];
int ps[50001];
int start[7];
int finish[7];
int ans = 0;

int main() {
  cin >> n;
  int a;
  for (int i = 0; i < n; i++) {
    cin >> cows[i + 1];
  }
  int t = 0;
  for (int i = 0; i <= n; i++) {
    ps[i] = t;
    t += cows[i + 1];
    t = t % 7;
  }
  for (int i = 0; i <= n; i++) {
    cout << ps[i] << ' ';
  }
  cout << endl;
  for (int i = 0; i < 7; i++) {
    start[i] = -1;
  }
  for (int i = 0; i <= n; i++) {
    if (start[ps[i]] == -1) {
      start[ps[i]] = i;
    }
    else {
      finish[ps[i]] = i;
    }
  }
  for (int i = 0; i < 7; i++) {
    ans = max(finish[i] - start[i], ans);
  }
  cout << ans << endl;
}