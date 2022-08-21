#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		if (M == 1 && N == 1) {
			cout << 0 << endl;
			continue;
		}
		else if (N == 1) {
			cout << M << endl;
			continue;
		}
		else if (M == 1) {
			cout << N << endl;
			continue;
		}
		int ans = N - 1 + M - 1;
		ans += min(N, M);
		cout << ans << endl;
	}
}
