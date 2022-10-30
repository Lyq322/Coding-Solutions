#include <iostream>
 
using namespace std;
typedef long long ll;
 
int n, k;
int numbers[200000];
 
bool check(ll num) {
  ll t = 0;
  int g = 1;
  for (int i = 0; i < n; i++) {
    if (numbers[i] > num) {
      return false;
    }
    if (t + numbers[i] <= num) {
      t += numbers[i];
    }
    else {
      t = numbers[i];
      g++;
    }
  }
  if (g > k) {
    return false;
  }
  return true;
}
 
int main() {
  cin >> n >> k;
  ll t = 0;
  for (int i = 0; i < n; i++) {
    cin >> numbers[i];
    t += numbers[i];
  }
  check(6);
  ll l = 1;
  ll r = t;
  while (l < r) {
    ll m = l + (r - l) / 2;
    if (check(m)) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
  cout << l << endl;
} 