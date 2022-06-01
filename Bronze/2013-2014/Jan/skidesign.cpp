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

int ski_design(int hills[], int N) {
  sort(hills, hills + N);
  /*for (int l = 0; l < N; l++) {
    cout << hills[l] << ' ';
  }*/
  long long int ans = 10000000000;
  for (int i = hills[0]; i < hills[N - 1]; i++) {
    int L = i;
    int R = i + 17;
    int up = ub(R, hills, N);
    int lo = lb(L, hills, N);
    int a = 0;
    //cout << 'L' << L << '\n';
    //cout << 'R' << R << '\n';
    //cout << "lo" << lo << '\n';
    //cout << "up" << up << '\n';
    for (int j = 0; j < lo; j++) {
      a = a + (L - hills[j]) * (L - hills[j]);
    }
    //cout << a << '\n';
    for (int k = up; k < N; k++) {
      a = a + (hills[k] - R) * (hills[k] - R);
    }
    //cout << a << '\n';
    if (a < ans) {
      ans = a;
    }
  }
  //cout << ans << '\n';
  return ans;
}
int main() {
  int N;
  cin >> N;
  int hills[N];
  for (int i = 0; i < N; i++) {
    cin >> hills[i];
  }
  int ans = ski_design(hills, N);
  cout << ans;
  return 0;
}