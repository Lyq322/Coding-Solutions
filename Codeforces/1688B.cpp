#include <bits/stdc++.h>
using namespace std;

int cal(int x) {
	int count = 0;
	while (x % 2 == 0) {
		x = x / 2;
		count++;
	}
	return count;
}

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N;
		cin >> N;
		int a;
		vector<int> v;
		int odd = 0;
		int even = 0;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
			if (a % 2 == 1) {
				odd++;
			}
			else {
				even++;
			}
		}
		if (odd > 0) {
			cout << even << endl;
			continue;
		}
		int ans = -1;
		for (int i = 0; i < N; i++) {
			int count = cal(v[i]);
			if (ans == -1 || ans > count) {
				ans = count;
			}
		}
		cout << ans + N - 1 << endl;
	}
}
