#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

typedef long long int ll;

ll n, b;
ll visited[65536];
ll state[16];
vector<ll> states;

void change() {
  ll copy_arr[16];
  for (ll i = 0; i < n; i++) {
    copy_arr[i] = state[i];
  }
  for (ll i = 0; i < n; i++) {
    if (i == 0) {
      if (copy_arr[n - 1] == 1) {
        if (state[0] == 0) {
          state[0] = 1;
        }
        else {
          state[0] = 0;
        }
      }
    }
    else {
      if (copy_arr[i - 1] == 1) {
        if (state[i] == 0) {
          state[i] = 1;
        }
        else {
          state[i] = 0;
        }
      }
    }
  }
}

ll bin_to_dec() {
  ll num = 0;
  for (ll i = 0; i < n; i++) {
    num += (ll) pow(2, i) * state[i];
  }
  return num;
}

void dec_to_bin(ll num) {
  ll two = n - 1;
  vector<ll> ans;
  while (two >= 0) {
    if (num >= (ll) pow(2, two)) {
      num -= (ll) pow(2, two);
      ans.push_back(1);
    }
    else {
      ans.push_back(0);
    }
    two--;
  }
  for (ll i = ans.size() - 1; i > -1; i--) {
    cout << ans[i] << endl;
  }
}

int main() {
  cin >> n >> b;
  for (ll i = 0; i < n; i++) {
    cin >> state[i];
  }
  for (ll i = 0; i < 65536; i++) {
    visited[i] = -1;
  }
  ll times = 0;
  ll index;
  while (times < b) {
    change();
    index = bin_to_dec();
    if (visited[index] == -1) {
      visited[index] = times;
      states.push_back(index);
    }
    else {
      break;
    }
    times++;
  }
  if (times == b) {
    dec_to_bin(states[times - 1]);
  }
  else {
    ll cycle = times - visited[index];
    ll times_left = b - times;
    ll cycle_index = times_left % cycle;
    if (cycle_index == 0) {
      cycle_index = cycle - 1;
    }
    else {
      cycle_index--;
    }
    cycle_index += visited[index];
    dec_to_bin(states[cycle_index]);
  }
} 