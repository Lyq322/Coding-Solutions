#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N;
		int a;
		vector<int> v;
		for (int j = 0; j < N; j++) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		int index = 0;
		int count = 0;
		int ans = 0;
		int even = 0;
		for (int j = 0; j < N; j++) {
			if (v[j] == v[index]) {
				count++;
			}
			else {
				if (count % 2 == 1) {
					ans++;
				}
				else {
					even++;
				}
				index = j;
				count = 1;
			}
		}
		if (count % 2 == 1) {
			ans++;
		}
		else {
			even++;
		}
		if (even % 2 == 0) {
			ans += even;
		}
		else {
			ans += even / 2 * 2;
		}
		cout << ans << endl;
	}
}
