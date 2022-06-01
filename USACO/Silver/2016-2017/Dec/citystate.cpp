#include <iostream>
#include <algorithm>

using namespace std;

int ub(string x, string arr[], int N) {
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

int lb(string x, string arr[], int N) {
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

int main() {
  int N;
  cin >> N;
  string city_states[N];
  string a, b;
  for (int i = 0; i < N; i++) {
    cin >> a >> b;
    city_states[i] = a.substr(0, 2) + b;
  }
  sort(city_states, city_states + N);
  string c;
  int ans = 0;
  for (int j = 0; j < N; j++) {
    c = city_states[j].substr(2, 2) + city_states[j].substr(0, 2);
    if (city_states[j].substr(2, 2) != city_states[j].substr(0, 2)) {
      ans += ub(c, city_states, N) - lb(c, city_states, N);
    }
  }
  cout << "ans " << ans / 2 << '\n';
}