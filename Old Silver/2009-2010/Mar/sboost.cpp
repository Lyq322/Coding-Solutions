#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
  int f;
  int m;
  double a;
  int l;
};

bool comp(Point x, Point y) {
  if (x.a != y.a) {
    return x.a > y.a;
  }
  if (x.m != y.m) {
    return x.m < y.m;
  } 
  return x.a > y.a;
}

int main() {
  int F, M, N;
  cin >> F >> M >> N;
  Point parts[N];
  int b, c;
  for (int i = 0; i < N; i++) {
    cin >> b >> c;
    parts[i].f = b;
    parts[i].m = c;
    parts[i].a = (double) b / c;
    parts[i].l = i + 1;
    //cout << "Force " << parts[i].f << " Mass " << parts[i].m << " Acceleration " << parts[i].a << '\n';
  }
  double A = (double) F / M;
  sort(parts, parts + N, comp);
  /*
  for (int j = 0; j < N; j++) {
    cout << parts[j].f << ' ' << parts[j].m << ' ' << parts[j].a << '\n';
  }*/
  vector<int> ans;
  for (int k = 0; k < N; k++) {
    if (parts[k].a <= A) {
      break;
    }
    else {
      ans.push_back(parts[k].l);
      F = F + parts[k].f;
      M = M + parts[k].m;
      A = (double) F / M;
    }
  }
  if (ans.size() == 0) {
    cout << "NONE\n";
  }
  else {
    sort(ans.begin(), ans.end());
    for (int l = 0; l < ans.size(); l++) {
      cout << ans[l] << '\n';
    }
  }
}