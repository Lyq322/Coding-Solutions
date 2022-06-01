#include <bits/stdc++.h>

using namespace std;

int N;
int grass[500][500];
bool ps1[501][501][501] = {{{0}}};
bool ps2[501][501][501] = {{{0}}};

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grass[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			bool b = true;
			for (int k = j; k < N; k++) {
				if (grass[i][k] < 100) {
					b = false;
				}
				ps1[i][j][k] = b;
			}
			b = true;
			for (int k = j; k < N; k++) {
				if (grass[i][k] <= 100) {
					b = false;
				}
				ps2[i][j][k] = b;
			}
		}
	}
	int t1 = 0;
	int t2 = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int r = 0;
			for (int k = 0; k < N; k++) {
				if (ps1[k][i][j]) {
					r++;
					t1 += r;
				}
				else {
					r = 0;
				}
			}
			r = 0;
			for (int k = 0; k < N; k++) {
				if (ps2[k][i][j]) {
					r++;
					t2 += r;
				}
				else {
					r = 0;
				}
			}
		}
	}
	//cout << t1 << ' ' << t2 << endl;
	cout << t1 - t2 << endl;
}
