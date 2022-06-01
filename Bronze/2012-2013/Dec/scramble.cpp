#include <iostream>
#include <algorithm>

using namespace std;

struct Pos {
  int s;
  int f;
};

struct Str {
  string s;
  int p;
};

int N;
Str words_f[50000];
Str words_b[50000];
Pos ans[50000];

bool comp(Str a, Str b) {
  return a.s < b.s;
}

int ub(string x, Str arr[]) {
  int L = 0;
  int R = N;
  int M;
  while (L < R) {
    M = (L + R) / 2;
    if (x >= arr[M].s) {
      L = M + 1;
    }
    else {
      R = M;
    }
  }
  return L;
}

int lb(string x, Str arr[]) {
  int L = 0;
  int R = N;
  int M;
  while (L < R) {
    M = (L + R) / 2;
    if (x <= arr[M].s) {
      R = M;
    }
    else {
      L = M + 1;
    }
  }
  return L;
}

string reverse(string x) {
  string s = "";
  for (int i = 0; i < x.size(); i++) {
    s += x.at(x.size() - i - 1);
  }
  return s;
}

int main() {
  cin >> N;
  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;
    sort(s.begin(), s.end());
    words_f[i].s = s;
    words_f[i].p = i;
    string s2 = reverse(s);
    words_b[i].s = s2;
    words_b[i].p = i;
  }
  sort(words_f, words_f + N, comp);
  sort(words_b, words_b + N, comp);
  /*
  for (int i = 0; i < N; i++) {
    cout << words_f[i].s << ' ' << words_f[i].p << ' ';
  }
  cout << endl;
  for (int i = 0; i < N; i++) {
    cout << words_b[i].s << ' ' << words_b[i].p << ' ';
  }
  cout << endl;*/
  string a;
  int b;
  for (int i = 0; i < N; i++) {
    a = reverse(words_f[i].s);
    b = lb(a, words_f);
    if (a == words_f[i].s) {
      ans[words_f[i].p].s = b + 1;
    }
    else {
      ans[words_f[i].p].s = b;
    }
  }
  for (int i = 0; i < N; i++) {
    a = reverse(words_b[i].s);
    b = ub(a, words_b);
    if (a == words_b[i].s) {
      ans[words_b[i].p].f = b;
    }
    else {
      ans[words_b[i].p].f = b + 1;
    }
  }
  int temp;
  for (int i = 0; i < N; i++) {
    if (ans[i].s > ans[i].f) {
      temp = ans[i].s;
      ans[i].s = ans[i].f;
      ans[i].f = temp;
    }
  }
  for (int i = 0; i < N; i++) {
    cout << ans[i].s << ' ' << ans[i].f << endl;
  }
}