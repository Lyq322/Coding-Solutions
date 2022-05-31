#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		vector<int> v;
		int a;
		int total = 0;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
			total += a;
		}
		if (total % N != 0) {
			cout << "NO" << endl;
			continue;
		}
		bool ans = false;
		for (int i = 0; i < N; i++) {
			if (v[i] == total / N) {
				ans = true;
				cout << "YES" << endl;
				break;
			}
		}
		if (!ans) cout << "NO" << endl;
	}
}
