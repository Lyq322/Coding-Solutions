#include <iostream>

using namespace std;

int N, B;
int best = 1000000;

void solve(int pos, int sum, int cows[]) {
  if (pos == N) {
    if (sum >= B) {
      if (sum - B < best) {
        best = sum - B;
      }
    }
    return;
  }
  solve(pos + 1, sum, cows);
  solve(pos + 1, sum + cows[pos], cows);
}

int main() {
  cin >> N >> B;
  int cows[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  solve(0, 0, cows);
  cout << best << '\n';
}