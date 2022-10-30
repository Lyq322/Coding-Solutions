#include <bits/stdc++.h>
using namespace std;

int main() {
	long long N;
	cin >> N;
	cout << N << ' ';
	while (N != 1) {
		if (N % 2 == 0) {
			N = N / 2;
		}
		else {
			N = 3 * N + 1;
		}
		cout << N << ' ';
	}
}
