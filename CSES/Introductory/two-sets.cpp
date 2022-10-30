#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	if (N == 3) {
		cout << "YES" << endl;
		cout << 1 << endl;
		cout << 3 << endl;
		cout << 2 << endl;
		cout << 1 << ' ' << 2 << endl;
	}
	else if (N % 2 == 0 && N % 4 != 0) cout << "NO" << endl;
	else if (N % 2 == 1 && (N + 1) % 4 != 0) cout << "NO" << endl;
	else if (N % 4 == 0) {
		cout << "YES" << endl;
		cout << N / 2 << endl;
		for (int i = 0; i < N / 4; i++) {
			cout << i + 1 << ' ';
		}
		for (int i = N - N / 4; i < N; i++) {
			cout << i + 1 << ' ';
		}
		cout << endl;
		cout << N / 2 << endl;
		for (int i = N / 4; i < N - N / 4; i++) {
			cout << i + 1 << ' ';
		}
		cout << endl;
	}
	else {
		cout << "YES" << endl;
		cout << 1 + (N - 3) / 2 << endl;
		for (int i = 4; i < (N - 3) / 4 + 4; i++) {
			cout << i << ' ';
		}
		for (int i = N - (N - 3) / 4 + 1; i <= N; i++) {
			cout << i << ' ';
		}
		cout << 3 << endl;
		cout << 2 + (N - 3) / 2 << endl;
		for (int i = (N - 3) / 4 + 4; i < N - (N - 3) / 4 + 1; i++) {
			cout << i << ' ';
		}
		cout << 1 << ' ' << 2 << endl;
		cout << endl;
	}
}
