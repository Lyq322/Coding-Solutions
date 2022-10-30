#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int prev = -1;
	int cur;
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		if (prev == -1) {
			prev = cur;
			continue;
		}
		if (cur < prev) {
			ans += prev - cur;
		}
		else {
			prev = cur;
		}
	}
	cout << ans << endl;
}
