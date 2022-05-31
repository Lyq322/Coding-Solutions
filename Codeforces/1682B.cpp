#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		int ans = -1;
		int a;
		for (int j = 0; j < N; j++) {
			cin >> a;
			if (a != j) {
				if (ans == -1) ans = a;
				else ans = ans & a;
			}
		}
		cout << ans << endl;
	}
}
