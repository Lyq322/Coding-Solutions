#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	int di[4] = {1, 1, -1, -1};
	int dj[4] = {-1, 1, -1, 1};
	for (int z = 0; z < T; z++) {
		char arr[8][8];
		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 1; i < 7; i++) {
			for (int j = 1; j < 7; j++) {
				bool c = true;
				if (arr[i][j] != '#') {
					continue;
				}
				for (int k = 0; k < 4; k++) {
					int a = i + di[k];
					int b = j + dj[k];
					if (arr[a][b] != '#') {
						c = false;
						break;
					}
				}
				if (c) {
					cout << i + 1 << ' ' << j + 1 << endl;
					break;
				}
			}
		}
	}
}
