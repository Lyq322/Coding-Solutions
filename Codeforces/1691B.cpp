#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		vector<int> v;
		int a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
		}
		a = 0;
		bool w = true;
		int ans[100000] = {0};
		while (a < N) {
			int b = N;
			for (int i = a; i < N; i++) {
				if (v[i] != v[a]) {
					b = i;
					break;
				}
				if (i != N - 1) {
					ans[i + 1] = i + 1;
				}
			}
			if (b == a + 1) {
				cout << -1 << endl;
				w = false;
				break;
			}
			ans[a] = b;
			a = b;
		}
		if (w) {
			for (int i = 0; i < N; i++) {
				cout << ans[i] << ' ';
			}
			cout << endl;
		}
	}
}
