#include <iostream>
 
using namespace std;
typedef long long ll;
 
int n;
ll arr[200000];
ll ps[200001];
ll maximum[200001];
 
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  ll t = 0;
  for (int i = 0; i < n; i++) {
    ps[i] = t;
    t += arr[i];
  }
  ps[n] = t;
  ll m = -1e18;
  for (int i = n; i > 0; i--) {
    m = max(m, ps[i]);
    maximum[i - 1] = m;
  }
  ll ans = -1e18;
  for (int i = 0; i < n; i++) {
    ans = max(ans, maximum[i] - ps[i]);
  }
  cout << ans << endl;
} 