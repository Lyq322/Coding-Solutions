#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N, K;
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N >> K;
		int arr[200000];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		if (K == 1) {
			cout << (N - 1) / 2 << endl;
		}
		else {
			int ans = 0;
			for (int i = 1; i < N - 1; i++) {
				if (arr[i] > arr[i - 1] + arr[i + 1]) {
					ans++;
				}
			}
			cout << ans << endl;
		}
	}
}
