#include <iostream>
#include <set>
#include <vector>

using namespace std;
typedef long long ll;

ll N;
ll homework[100000];
ll minimum[100000];
ll ps[100000];

int main() {
  cin >> N;
  for (ll i = 0; i < N; i++) {
    cin >> homework[i];
  }
  ll m = homework[N - 1];
  for (ll i = N - 1; i > -1; i--) {
    m = min(m, homework[i]);
    minimum[i] = m;
  }
  ll total = 0;
  for (ll i = N - 1; i > -1; i--) {
    total += homework[i];
    ps[i] = total - minimum[i];
  }
  ll numerator = 0;
  ll denominator = 1;
  vector<ll> v;
  for (ll i = 1; i < N - 1; i++) {
    if (ps[i] * denominator > numerator * (N - i - 1)) {
      numerator = ps[i];
      denominator = N - i - 1;
      v.clear();
      v.push_back(i);
    }
    else if (ps[i] * denominator == numerator * (N - i - 1)) {
      v.push_back(i);
    }
  }
  for (ll i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}