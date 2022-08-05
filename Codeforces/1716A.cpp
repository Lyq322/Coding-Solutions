#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int ans = 0;
		if (N == 1) {
			cout << 2 << endl;
			continue;
		}
		else if (N % 3 == 1) {
			ans = (N - 3) / 3;
			ans += 2;
		}
		else if (N % 3 == 2) {
			ans = N / 3 + 1;
		}
		else {
			ans = N / 3;
		}
		cout << ans << endl;
	}
}
