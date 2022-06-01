#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Cow {
  bool spot;
  long long int weight;
};

struct Range {
  long long int l;
  long long int r;
};

long long int N, A, B;
Cow cows[50000];
vector<Range> intervals;
long long int ans = 0;

bool comp(Cow a, Cow b) {
  return a.weight < b.weight;
}

int main() {
  cin >> N >> A >> B;
  string s;
  long long int w;
  for (int i = 0; i < N; i++) {
    cin >> s >> w;
    if (s == "S") {
      cows[i].spot = true;
      cows[i].weight = w;
    }
    else {
      cows[i].spot = false;
      cows[i].weight = w;
    }
  }
  sort(cows, cows + N, comp);
  if (cows[0].spot) {
    intervals.push_back({1, (cows[0].weight + cows[1].weight) / 2});
  } 
  long long int st, fi;
  for (int i = 1; i < N - 1; i++) {
    if (cows[i].spot) {
      fi = (cows[i + 1].weight + cows[i].weight) / 2;
      if ((cows[i].weight + cows[i - 1].weight) % 2 == 0) {
        st = (cows[i].weight + cows[i - 1].weight) / 2;
        if (cows[i - 1].spot) {
          st = st + 1;
        }
      }
      else {
        st = (cows[i].weight + cows[i - 1].weight) / 2 + 1;
      }
      intervals.push_back({st, fi});
    }
  }
  if (cows[N - 1].spot) {
    intervals.push_back({(cows[N - 2].weight + cows[N - 1].weight) / 2, 1000000000});
  }
  for (int i = 0; i < intervals.size(); i++) {
    if (A <= intervals[i].l && intervals[i].r <= B) {
      ans = ans + intervals[i].r - intervals[i].l + 1;
    }
    else if (intervals[i].l <= A && A <= intervals[i].r) {
      ans = ans + intervals[i].r - A + 1;
    }
    else if (intervals[i].l <= B && B <= intervals[i].r) {
      ans = ans + B - intervals[i].l + 1;
    }
  }
  cout << ans << endl;
}