#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;

ll N, K, M;

bool check(ll X) {
  ll left = N;
  ll i = K;
  while (i > 0) {
    ll Y = left / X;
    if (Y < M) {
      if (i * M >= left) {
        return true;
      }
      return false;
    }
    ll bound = (left % X) / Y;
    ll subtractDays = min(bound + 1, i);
    i -= subtractDays;
    left -= Y * subtractDays;
    if (left <= 0) {
      return true;
    }

  }
  return false;
}

int main() {
  cin >> N >> K >> M;
  ll l = 1;
  ll r = pow(10, 12);
  ll m;
  check(2);
  while (l < r - 1) {
    m = l + (r - l) / 2;
    if (check(m)) {
      l = m;
    }
    else {
      r = m;
    }
  }
  cout << l << endl;
}