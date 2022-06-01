#include <iostream>

using namespace std;
typedef pair<int, int> pii;

const int max_n = 100002;
const int max_q = 100002;

int n, q;
int color[max_n];
pii queries[max_q];
int last_appearance[max_n][27];
int last_appearance2[max_n][27];
int rem[27];
int forward_arr[max_n];
int backward_arr[max_n];

int main() {
  cin >> n >> q;
  string s;
  cin >> s;
  for (int i = 0; i < q; i++) {
    cin >> queries[i].first >> queries[i].second;
  }
  for (int i = 0; i < n; i++) {
    color[i] = s[i];
    color[i] -= 64;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      last_appearance[i][j] = -1;
      last_appearance2[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    int cur = color[i];
    for (int j = cur; j < 26; j++) {
      last_appearance[i][j] = i;
    }
    if (i != 0) {
      for (int j = 0; j < cur; j++) {
        last_appearance[i][j] = last_appearance[i - 1][j];
      }
    }
  }
  for (int i = n - 1; i > -1; i--) {
    int cur = color[i];
    for (int j = cur; j < 26; j++) {
      last_appearance2[i][j] = n - i - 1;
    }
    if (i != n - 1) {
      for (int j = 0; j < cur; j++) {
        last_appearance2[i][j] = last_appearance2[i + 1][j];
      }
    }
  }
  for (int i = 1; i <= 26; i++) {
    rem[i] = -1;
  }
  int paint = 1;
  rem[color[0]] = 0;
  forward_arr[0] = 1;
  for (int i = 1; i < n; i++) {
    int cur = color[i];
    if (rem[cur] == -1) {
      paint++;
    }
    else if (cur == 1) {

    }
    else {
      if (last_appearance[i - 1][cur - 1] > rem[cur]) {
        paint++;
      }
    }
    rem[cur] = i;
    forward_arr[i] = paint;
  }
  for (int i = 1; i <= 26; i++) {
    rem[i] = -1;
  }
  paint = 1;
  rem[color[n - 1]] = 0;
  backward_arr[n - 1] = 1;
  for (int i = n - 2; i > -1; i--) {
    int cur = color[i];
    if (rem[cur] == -1) {
      paint++;
    }
    else if (cur == 1) {

    }
    else {
      if (last_appearance2[i + 1][cur - 1] > rem[cur]) {
        paint++;
      }
    }
    rem[cur] = n - i - 1;
    backward_arr[i] = paint;
  }
  for (int i = 0; i < q; i++) {
    cout << forward_arr[queries[i].first - 2] + backward_arr[queries[i].second] << endl;
  }
} 