#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string to_bin(ll x) {
	string s = "";
	for (ll index = 30; index > -1; index--) {
		if (x >= (ll) pow(2, index)) {
			x -= (ll) pow(2, index);
			s += '1';
		}
		else {
			s += '0';
		}
	}
	return s;
}

int main() {
	ll T;
	cin >> T;
	ll a;
	for (ll i = 0; i < T; i++) {
		cin >> a;
		string s = to_bin(a);
		ll ones = 0;
		ll last_one, last_zero;
		for (ll j = 0; j <= 30; j++) {
			if (s.at(j) == '1') {
				ones++;
				last_one = j;
			}
			else {
				last_zero = j;
			}
		}
		if (ones >= 2) {
			cout << (ll) pow(2, 30 - last_one) << endl;
		}
		else {
			cout << (ll) pow(2, 30 - last_zero) + (ll) pow(2, 30 - last_one) << endl;
		}
	}
}
