#include <iostream>

using namespace std;

int N;
int speed[100000];
int location[100000];
int ans = 0;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> location[i] >> speed[i];
  }
  int minimum = -1;
  for (int i = N - 1; i > -1; i--) {
    if (minimum == -1 || speed[i] < minimum) {
      ans++;
      minimum = speed[i];
    }
    else if (minimum == speed[i]) {
      if (location[i + 1] - location[i] > 1) {
        ans++;
      }
    }
  }
  cout << ans << endl;
}