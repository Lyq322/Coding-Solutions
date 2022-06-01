#include <iostream>
#include <algorithm>

using namespace std;

int N;
int x[50000], y[50000], x_copy[50000], y_copy[50000];
int ans = -1;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i];
    x_copy[i] = x[i];
    y_copy[i] = y[i];
  }
  sort(x_copy, x_copy + N);
  sort(y_copy, y_copy + N);
  for (int i = 0; i < 4; i++) {
    for (int j = N - 1; j > N - 4; j--) {
      for (int k = 0; k < 4; k++) {
        for (int l = N - 1; l > N - 4; l--) {
          int count = 0;
          for (int m = 0; m < N; m++) {
            if (x_copy[i] <= x[m] && x[m] <= x_copy[j] && y_copy[k] <= y[m] && y[m] <= y_copy[l]) {
              count++;
            }
          }
          if (count >= N - 3) {
            int area = (x_copy[j] - x_copy[i]) * (y_copy[l] - y_copy[k]);
            if (ans == -1 || area < ans) {
              ans = area;
            }
          }
          
        }
      }
    }
  }
  cout << ans << endl;
}
