#include <iostream>

using namespace std;

int N, K, B;
int a[100001] = {0};
int road[100001];
int ans = -1;

int main() {
  cin >> N >> K >> B;
  int pos;
  for (int i = 0; i < B; i++) {
    cin >> pos;
    a[pos] = 1;
  }
  int b = 0;
  for (int i = 1; i < N + 1; i++) {
    b = b + a[i];
    road[i] = b;
  }
  road[0] = 0;
  int fix;
  for (int i = 0; i < N - K; i++) {
    fix = road[i + K] - road[i];
    if (ans == -1 || ans > fix) {
      ans = fix;
    }
  }
  cout << ans << endl;
}