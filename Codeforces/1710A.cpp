#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N, M, K;
		cin >> N >> M >> K;
		int colors[100000];
		for (int i = 0; i < K; i++) {
			cin >> colors[i];
		}
		// vertical
		int v[100000] = {0};
		for (int i = 0; i < K; i++) {
			v[i] = colors[i] / N;
		}
		sort(v, v + K, greater<int>());
		long long t = 0;
		for (int i = 0; i < K; i++) {
			if (t == M - 1) {
				if (v[0] > 2 && v[i] > 1) {
					t = M;
				}
				else {
					break;
				}
			}
			if (v[i] > 1) t += v[i];
			if (t >= M) break;
		}
		if (t >= M) {
			cout << "Yes\n";
			continue;
		}
		// horizontal
		int h[100000] = {0};
		for (int i = 0; i < K; i++) {
			h[i] = colors[i] / M;
		}
		sort(h, h + K, greater<int>());
		t = 0;
		for (int i = 0; i < K; i++) {
			if (t == N - 1) {
				if (h[0] > 2 && h[i] > 1) {
					t = N;
				}
				else {
					break;
				}
			}
			if (h[i] > 1) t += h[i];
			if (t >= N) break;
		}
		if (t >= N) {
			cout << "Yes\n";
		}
		else cout << "No\n";
	}
}
