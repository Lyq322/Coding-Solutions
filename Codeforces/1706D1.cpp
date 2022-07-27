#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, K;
		cin >> N >> K;
		int arr[3000];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + N);
		int ans = 2000000000;
		for (int i = 1; i <= arr[0]; i++) {
			int p = 1;
			while (true) {
				if (arr[0] / (p + 1) < i) {
					break;
				}
				p++;
			}
			p = min(p, K);
			int minimum = arr[0] / p;
			int maximum = arr[0] / p;
			for (int j = 1; j < N; j++) {
				while (true) {
					if (arr[j] / (p + 1) >= i) p++;
					else break;
				}
				p = min(p, K);
				maximum = max(maximum, arr[j] / p);
				minimum = min(minimum, arr[j] / p);
			}
			ans = min(ans, maximum - minimum);
		}
		cout << ans << endl;
	}
}
