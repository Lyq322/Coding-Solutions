#include <iostream>

using namespace std;

int c, n;
int cows[16];
int maximum = 0;

void solve(string s, int weights) {
  cout << s << ' ' << weights << endl;
  cin.ignore();
  if (s.length() == n) {
    maximum = max(maximum, weights);
    return;
  }
  solve(s + '0', weights);
  if (weights + cows[s.length()] <= c) {
    solve(s + '1', weights + cows[s.length()]);
  }
}

int main() {
  cin >> c >> n;
  for (int i = 0; i < n; i++) {
    cin >> cows[i];
  }
  solve("", 0);
  cout << maximum << endl;
}