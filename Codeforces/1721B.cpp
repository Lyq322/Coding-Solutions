#include <bits/stdc++.h>
using namespace std;

int di[4] = {0, 1, -1, 0};
int dj[4] = {1, 0, 0, -1};

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M, sx, sy, d;
		cin >> N >> M >> sx >> sy >> d;
		sx--;
		sy--;
		if (abs(N - sx) + abs(M - sy) <= d) {
			cout << -1 << endl;
		}
		else if (abs(sx) + abs(sy) <= d) {
			cout << -1 << endl;
		}
		else if (sx - d <= 0 && sx + d >= N - 1) {
			cout << -1 << endl;
		}
		else if (sy - d <= 0 && sy + d >= M - 1) {
			cout << -1 << endl;
		}
		else if (sx + d >= N - 1 && sy + d >= M - 1) {
			cout << -1 << endl;
		}
		else if (sx - d <= 0 && sy - d <= 0) {
			cout << -1 << endl;
		}
		else {
			cout << N - 1 + M - 1 << endl;
		}
	}
}
