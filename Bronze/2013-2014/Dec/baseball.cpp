#include <iostream>
#include <algorithm>

using namespace std;

int ub(int x, int arr[], int N) {
  int L = 0;
  int R = N;
  int M;
  while (L < R) {
    M = (L + R) / 2;
    if (x >= arr[M]) {
      L = M + 1;
    }
    else {
      R = M;
    }
  }
  return L;
}

int lb(int x, int arr[], int N) {
  int L = 0;
  int R = N;
  int M;
  while (L < R) {
    M = (L + R) / 2;
    if (x <= arr[M]) {
      
      R = M;
    }
    else {
      L = M + 1;
    }
  }
  return L;
}

int cow_baseball(int cows[], int N) {
  sort(cows, cows + N);
  /*
  for (int k = 0; k < N; k++) {
    cout << cows[k] << ' ';
  }*/
  //cout << '\n';
  int ans = 0;
  int d;
  int a;
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      d = cows[j] - cows[i];
      //cout << 'd' << d << " j" << j << '\n';
      a = ub(cows[j] + 2 * d, cows, N) - lb(cows[j] + d, cows, N);
      //cout << a << '\n';
      ans = ans + a;
      //cout << ans;
    }
  }
  return ans;
}

int main() {
  int N;
  cin >> N;
  int cows[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  cout << cow_baseball(cows, N);
  return 0;
}