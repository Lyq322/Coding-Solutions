#include <bits/stdc++.h>
using namespace std;

bool check(int t, int s) {
	if (t < 10) {
		if (s % 10 == 0 && t == s / 10) {
			return true;
		}
	}
	else {
		if (s % 10 == t / 10 && t % 10 == s / 10) {
			return true;
		}
	}
	return false;
}

int main() {
	int T;
	cin >> T;
	int t, s;
	char c;
	int loop;
	for (int z = 0; z < T; z++) {
		cin >> t >> c >> s >> loop;
		int ans = 0;
		bool time[24][60] = {{0}};
		time[t][s] = true;
		if (check(t, s)) {
			ans++;
		}
		while (true) {
			s += loop;
			while (s >= 60) {
				s -= 60;
				t++;
				if (t == 24) {
					t = 0;
				}
			}
			if (time[t][s]) {
				break;
			}
			else {
				time[t][s] = true;
			}
			if (check(t, s)) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
