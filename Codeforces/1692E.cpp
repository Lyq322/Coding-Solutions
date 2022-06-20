#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N, K;
		cin >> N >> K;
		int arr[200000];
		int one = 0;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (arr[i] == 1) {
				one++;
				v.push_back(i);
			}
		}
		if (one < K) {
			cout << -1 << endl;
			continue;
		}
		else if (one == K) {
			cout << 0 << endl;
			continue;
		}
		int i = 0;
		int j = K - 1;
		int ans = -1;
		for (int k = 0; k < v.size() - K + 1; k++) {
			int cal = 0;
			if (i == 0) {
				cal += N - v[j + 1];
			}
			else if (j == v.size() - 1) {
				cal += v[i - 1] + 1;
			}
			else {
				cal += N - v[j + 1] + v[i - 1] + 1;
			}
			if (ans == -1 || ans > cal) {
				ans = cal;
			}
			i++;
			j++;
		}
		cout << ans << endl;
	}
}
