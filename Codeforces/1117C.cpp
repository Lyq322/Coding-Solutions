#include <iostream>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int n;
ll sx, sy, fx, fy;
string wind;
ll wind_x = 0, wind_y = 0;

bool check(ll days) {
  ll cycles = days / n;
  ll remainder = days % n;
  ll new_x = sx + cycles * wind_x;
  ll new_y = sy + cycles * wind_y;
  for (int i = 0; i < remainder; i++) {
    if (wind[i] == 'U') {
      new_y++;
    }
    else if (wind[i] == 'D') {
      new_y--;
    }
    else if (wind[i] == 'L') {
      new_x--;
    }
    else {
      new_x++;
    }
  }
  ll remainding_days = abs(fx - new_x) + abs(fy - new_y);
  //cout << remainding_days << endl;
  if (remainding_days <= days) {
    return true;
  }
  return false;
}

int main() {
  cin >> sx >> sy >> fx >> fy >> n;
  cin >> wind;
  for (int i = 0; i < n; i++) {
    if (wind[i] == 'U') {
      wind_y++;
    }
    else if (wind[i] == 'D') {
      wind_y--;
    }
    else if (wind[i] == 'L') {
      wind_x--;
    }
    else {
      wind_x++;
    }
  }
  ll l = 1;
  ll r = 100000000000000;
  ll valid = -1;
  while (l <= r) {
    ll m = l + (r - l) / 2;
    if (check(m)) {
      valid = m;
      r = m - 1;
    }
    else {
      l = m + 1;
    }
  }
  cout << valid << endl;
} 