#include <iostream>
#include <algorithm>

using namespace std;

int N, K;
int ps[1000002] = {0};
int hay[1000002] = {0};

int main() {
  cin >> N >> K;
  int a, b;
  for (int i = 0; i < K; i++) {
    cin >> a >> b;
    ps[a-1] += 1;
    ps[b] -= 1;
  }
  for (int i = 0; i < N; i++) {
    cout << ps[i] << ' ';
  }
  cout << endl;
  int t = 0;
  for (int i = 0; i < N; i++) {
    t = t + ps[i];
    hay[i] = t;
  }
  sort(hay, hay + N);
  for (int i = 0; i < N; i++) {
    cout << hay[i] << ' ';
  }
  cout << endl;
  cout << hay[N / 2] << endl;
}