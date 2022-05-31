#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int a;
		vector<int> v;
		for (int j = 0; j < N; j++) {
			cin >> a;
			v.push_back(a);
		}
		sort(v.begin(), v.end());
		a = v[0];
		int t_char = 0;
		bool b;
		int d = 0;
		for (int j = 0; j < N; j++) {
			if (j == 0 || a != v[j]) {
				a = v[j];
				t_char++;
				b = true;
			}
			else if (a == v[j] && b) {
				b = false;
				d++;
			}
		}
		int ans = d;
		ans += (t_char - d + 1) / 2;
		cout << ans << endl;
	}
}
