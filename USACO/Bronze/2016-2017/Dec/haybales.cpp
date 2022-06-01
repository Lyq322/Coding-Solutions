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

int counting_haybales(int hay[], int L, int R, int N) {
  return ub(R, hay, N) - lb(L, hay, N);
}

int main() {
  int N, Q;
  cin >> N >> Q;
  int hay[N];
  for (int i = 0; i < N; i++) {
    cin >> hay[i];
  }
  sort(hay, hay + N);
  /*
  for (int k = 0; k < N; k++) {
    cout << hay[k] << ' ';
  } */
  //cout << '\n';
  int L, R;
  int ans[Q];
  for (int j = 0; j < Q; j++) {
    cin >> L;
    cin >> R;
    //cout << 'L' << L << ' ';
    //cout << 'R' << R << '\n';
    ans[j] = counting_haybales(hay, L, R, N);
    //cout << ans[j] << ' ';
  }
  for (int l = 0; l < Q; l++) {
    cout << ans[l] << '\n';
  }
  return 0;
}