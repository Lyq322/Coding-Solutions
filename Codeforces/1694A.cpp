#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int a, b;
		cin >> a >> b;
		for (int i = 0; i < min(a, b) * 2; i++) {
			if (i % 2 == 0) {
				cout << 0;
			}
			else {
				cout << 1;
			}
		}
		if (a > b) {
			for (int i = 0; i < a - b; i++) {
				cout << 0;
			}
		}
		else {
			for (int i = 0; i < b - a; i++) {
				cout << 1;
			}
		}
		cout << endl;
	}
}
