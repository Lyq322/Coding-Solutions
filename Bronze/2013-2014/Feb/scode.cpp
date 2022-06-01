#include <bits/stdc++.h>
using namespace std;

int ans = 0;

void solve(string s) {
	if (s.length() % 2 == 0) {
		return;
	}
	if (s.length() == 1) {
		return;
	}
	bool b1 = true;
	for (int i = 0; i < s.length()/ 2; i++) {
		if (s.at(i) != s.at(i + s.length() / 2 + 1)) {
			b1 = false;
			break;
		}
	}
	if (b1) {
		ans += 2;
		solve(s.substr(0, s.length() / 2 + 1));
		solve(s.substr(s.length() / 2, s.length() / 2 + 1));
	}
	bool b2 = true;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s.at(i) != s.at(i + s.length() / 2)) {
			b2 = false;
			break;
		}
	}
	if (b2) {
		ans++;
		solve(s.substr(s.length() / 2, s.length() / 2 + 1));
	}
	bool b3 = true;
	for (int i = 0; i < s.length() / 2; i++) {
		if (s.at(i + 1) != s.at(i + s.length() / 2 + 1)) {
			b3 = false;
			break;
		}
	}
	if (b3) {
		ans++;
		solve(s.substr(0, s.length() / 2 + 1));
	}
}

int main() {
	string s;
	cin >> s;
	solve(s);
	cout << ans << endl;
}
