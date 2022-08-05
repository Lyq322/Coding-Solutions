#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int arr[2][200000];
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				cin >> arr[i][j];
			}
		}
		int time = 0;
		int new_arr1[2][200000];
		int new_arr2[2][200000];
		for (int j = 0; j < N; j++) {
			new_arr1[0][j] = arr[0][j] - j + 1;
		}
		for (int j = 0; j < N; j++) {
			new_arr1[1][j] = arr[1][j] - N + j - N + 2;
		}
		for (int j = 0; j < N; j++) {
			new_arr2[0][j] = arr[0][j] - N + j - N + 2;
		}
		for (int j = 0; j < N; j++) {
			new_arr2[1][j] = arr[1][j] - j + 1;
		}
		new_arr1[0][0] = 0;
		new_arr2[0][0] = 0;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				new_arr1[i][j] = max(new_arr1[i][j], 0);
				new_arr2[i][j] = max(new_arr2[i][j], 0);
			}
		}
		int max_arr1[200000];
		max_arr1[N - 1] = max(new_arr1[0][N - 1], new_arr1[1][N - 1]);
		for (int i = N - 2; i > -1; i--) {
			max_arr1[i] = max(max_arr1[i + 1], max(new_arr1[0][i], new_arr1[1][i]));
		}
		int max_arr2[200000];
		max_arr2[N - 1] = max(new_arr2[0][N - 1], new_arr2[1][N - 1]);
		for (int i = N - 2; i > -1; i--) {
			max_arr2[i] = max(max_arr2[i + 1], max(new_arr2[0][i], new_arr2[1][i]));
		}
		int ans = max_arr1[0] + 2 * N - 1;
		for (int i = 0; i < N; i++) {
			//cout << "i " << i << endl;
			if (i % 2 == 0) {
				if (i != 0) time = max(time, arr[0][i]) + 1;
				//time = max(time, arr[0][i]) + 1;
				//cout << time << ' ';
				time = max(time, arr[1][i]) + 1;
				//cout << time << ' ';
				int max_straight = time;
				if (i != N - 1) max_straight = max(max_straight, max_arr2[i + 1] + i);
				max_straight += (N - i - 1) * 2;
				//cout << max_straight << endl;
				ans = min(ans, max_straight);
			}
			else {
				time = max(time, arr[1][i]) + 1;
				time = max(time, arr[0][i]) + 1;
				//cout << time << ' ';
				int max_straight = time;
				if (i != N - 1) max_straight = max(max_straight, max_arr1[i + 1] + i);
				max_straight += (N - i - 1) * 2;
				//cout << max_straight << endl;
				ans = min(ans, max_straight);
			}
		}
		cout << ans << endl;
	}
}
