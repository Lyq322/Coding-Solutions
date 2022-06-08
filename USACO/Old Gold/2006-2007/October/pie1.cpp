#include <bits/stdc++.h>
using namespace std;

int R, C;
int di[3] = {0, 1, -1};

int main() {
	cin >> R >> C;
	int arr[100][100];
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (i >= 1 + j) {
				arr[i][j] = 0;
			}
		}
	}
	for (int i = 1; i < C; i++) {
		for (int j = 0; j < R; j++) {
			int maximum = 0;
			for (int k = 0; k < 3; k++) {
				int a = j + di[k];
				int b = i - 1;
				if (a >= 0 && a < R) {
					maximum = max(maximum, arr[a][b]);
				}
			}
			arr[j][i] += maximum;
		}
	}
	cout << arr[R - 1][C - 1] << endl;
}
