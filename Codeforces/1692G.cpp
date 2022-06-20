#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N, K;
		cin >> N >> K;
		int arr[200000];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		bool two[200000];
		for (int i = 0; i < N - 1; i++) {
			if (arr[i] < arr[i + 1] * 2) {
				two[i] = true;
			}
			else {
				two[i] = false;
			}
		}
		int i = 0;
		int j = 0;
		int ans = 0;
		while (i < N - 1 && j < N - 1) {
			if (!two[j]) {
				i = j + 1;
				j++;
			}
			else {
				int count = j - i + 2;
				if (count >= K + 1) {
					ans++;
				}
				j++;
			}
		}
		cout << ans << endl;
	}
}
