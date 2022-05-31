#include <bits/stdc++.h>

using namespace std;

int main() {
	int T;
	cin >> T;
	int N;
	string s;
	for (int i = 0; i < T; i++) {
		cin >> N;
		cin.ignore();
		getline(cin, s);
		char c = s.at(N / 2);
		int ans = 0;
		for (int i = N / 2; i < N; i++) {
			if (s.at(i) == c) {
				ans++;
			}
			else {
				break;
			}
		}
		if (N % 2 == 0) cout << ans * 2 << endl;
		else cout << ans * 2 - 1 << endl;
	}
}
