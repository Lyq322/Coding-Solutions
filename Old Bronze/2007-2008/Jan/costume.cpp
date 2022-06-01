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

int costume_party(int cows[], int N, int S) {
  sort(cows, cows + N);
  /*
  for (int j = 0; j < N; j++) {
    cout << cows[j] << " ";
  }
  cout << '\n'; */
  int ans = 0;
  int a;
  for (int i = 0; i < N - 1; i++) {
    if (cows[i] >= S) {
      break;
    }
    //cout << ub(S - cows[i], cows, N) << ' ' << max(lb(cows[i], cows, N), i);
    a = ub(S - cows[i], cows, N) - max(lb(cows[i], cows, N), i) - 1;
    //cout << 'a' << a << '\n';
    if (a > 0) {
      ans = ans + a;
    }
  }
  return ans;
}

int main() {
  int N, S;
  cin >> N >> S;
  int cows[N];
  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  cout << costume_party(cows, N, S);
  return 0;
}