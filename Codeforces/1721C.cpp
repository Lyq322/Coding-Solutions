#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int a[200000];
		int b[200000];
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> b[i];
		}
		sort(a, a + N);
		for (int i = 0; i < N; i++) {
			auto it = lower_bound(b, b + N, a[i]);
			if (it - b == N) {

			}
			else {
				cout << b[it - b] - a[i] << ' ';
			}
		}
		cout << endl;
		if (N == 1) {
			cout << b[0] - a[0] << endl;
			continue;
		}
		int index = 0;
		for (int i = 1; i < N; i++) {
			if (b[i - 1] < a[i]) {
				for (int j = index; j < i; j++) {
					cout << b[i - 1] - a[j] << ' ';
				}
				index = i;
				if (i == N - 1) {
					cout << b[i] - a[i];
					break;
				}
			}
			else {
				if (i == N - 1) {
					for (int j = index; j < N - 1; j++) {
						cout << b[N - 1] - a[j] << ' ';
					}
					cout << b[N - 1] - a[N - 1] << ' ';
					break;
				}
			}
		}
		cout << endl;
	}
}
