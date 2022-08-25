#include <bits/stdc++.h>
using namespace std;

/*
Define check_row[i][j][k] as if it there is no X at row i from column j through k, inclusive
Loop over column i, j
Use a two pointers on the row to check if the rectangle with row p1-p2, column i-j works
*/

int main() {
	int N, M;
	cin >> N >> M;
	char arr[200][200];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	bool check_row[200][200][200];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'X') check_row[i][j][j] = false;
			else check_row[i][j][j] = true;
			for (int k = j + 1; k < M; k++) {
				if (arr[i][k] == 'X') {
					check_row[i][j][k] = false;
				}
				else {
					check_row[i][j][k] = check_row[i][j][k - 1];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		for (int j = i; j < M; j++) {
			int p1 = -1;
			for (int k = 0; k < N; k++) {
				if (p1 == -1) {
					if (check_row[k][i][j]) {
						p1 = k;
					}
				}
				else {
					if (check_row[k][i][j]) {
						ans = max(ans, (j - i + 1) * (k - p1 + 1));
					}
					if (arr[k][i] == 'X' || arr[k][j] == 'X') {
						p1 = -1;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
