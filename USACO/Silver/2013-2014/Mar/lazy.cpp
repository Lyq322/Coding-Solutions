#include <bits/stdc++.h>
using namespace std;

/*
The shape of all grass that can be eaten by Bessie from a position (i, j) is (usually) a square that is rotated by 45 degrees
We can rotate the input array by 45 degrees so that the answer is easier to calculate, filling in zeroes if necessary
2D prefix sum to find answer
*/

int main() {
	int N, M;
	cin >> N >> M;
	int arr[400][400];
	int new_arr[800][800] = {{0}};
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		int sx = i;
		int sy = 0;
		for (int j = 0; j < N; j++) {
			new_arr[i + 1][N - i + 2 * j] = arr[sx][sy];
			if (sx - 1 < 0) {
				break;
			}
			sx--;
			sy++;
		}
	}
	for (int i = 1; i < N; i++) {
		int sx = N - 1;
		int sy = i;
		for (int j = 1; j < N; j++) {
			new_arr[i + N][i + 2 * (j - 1) + 1] = arr[sx][sy];
			if (sy + 1 >= N) {
				break;
			}
			sx--;
			sy++;
		}
	}
	for (int i = 0; i < 2 * N; i++) {
		for (int j = 0; j < 2 * N; j++) {
			new_arr[i][j] += new_arr[i - 1][j] + new_arr[i][j - 1] - new_arr[i - 1][j - 1];
		}
	}
	if (M >= N - 1) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans += arr[i][j];
			}
		}
		cout << ans << endl;
	}
	else {
		int ans = 0;
		for (int i = 2 * M + 1; i < 2 * N; i++) {
			for (int j = 2 * M + 1; j < 2 * N; j++) {
				int total = new_arr[i][j] - new_arr[i - 2 * M - 1][j] - new_arr[i][j - 2 * M - 1] + new_arr[i - 2 * M - 1][j - 2 * M - 1];
				ans = max(ans, total);
			}
		}
		cout << ans << endl;
	}
}
