#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

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
  int M, N;
  cin >> M >> N;
  cin.ignore();
  string d;
  string phrases[M];
  for (int i = 0; i < M; i++) {
    getline(cin, d);
    phrases[i] = d;
  }
  string recordings[N];
  for (int i = 0; i < N; i++) {
    getline(cin, d);
    recordings[i] = d;
  }
  sort(phrases, phrases + M);
  for (int i = 0; i < M; i++) {
  }
  int a;
  bool b;
  int ans = 0;
  string f, g;
  for (int k = 0; k < N; k++) {
    a = lb(recordings[k], phrases, M);
    f = recordings[k];
    g = phrases[a];
    if (f.length() <= g.length()) {
      b = true;
      
      for (int l = 0; l < f.length(); l++) {
        if (f.at(l) != g.at(l)) {
          b = false;
          break;
        }
      }
      
      if (b == true) {
        ans++;
      }
    }
  }
  cout << ans;
}