#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, H, M;
		cin >> N >> H >> M;
		int a, b;
		int ans_h = -1;
		int ans_m = -1;
		for (int i = 0; i < N; i++) {
			cin >> a >> b;
			int hours = (a - H + 24) % 24;
			int minutes = b - M;
			if (minutes < 0) {
				hours = (hours + 23) % 24;
				minutes += 60;
			}
			if (ans_h == -1 || ans_h > hours || (ans_h == hours && ans_m > minutes)) {
				ans_h = hours;
				ans_m = minutes;
			}
		}
		cout << ans_h << ' ' << ans_m << endl;
	}
}
