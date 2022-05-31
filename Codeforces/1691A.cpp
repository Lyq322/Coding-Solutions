#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		int a;
		int odd = 0;
		int even = 0;
		for (int i = 0; i < N; i++) {
			cin >> a;
			if (a % 2 == 0) {
				even++;
			}
			else {
				odd++;
			}
		}
		cout << min(even, odd) << endl;
	}
}
