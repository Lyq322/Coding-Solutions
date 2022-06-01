#include <iostream>

using namespace std;

int C, B;
int *food;
int best = 0;

void solve(int pos, int calories) {
  if (pos == B) {
    if (calories > best) {
      best = calories;
    }
    return;
  }
  if (calories + food[pos] <= C) {
    solve(pos + 1, calories + food[pos]);
  }
  solve(pos + 1, calories);
}

int main() {
  cin >> C >> B;
  food = new int[B];
  for (int i = 0; i < B; i++) {
    cin >> food[i];
  }
  solve(0, 0);
  cout << best << endl;
}