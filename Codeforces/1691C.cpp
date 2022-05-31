#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N >> K;
		vector<char> v;
		char c;
		for (int i = 0; i < N; i++) {
			cin >> c;
			v.push_back(c);
		}
		int t = 0;
		for (int i = 0; i < N - 1; i++) {
			if (v[i] == '1') {
				t += 10;
			}
			if (v[i + 1] == '1') {
				t++;
			}
		}
		int index1 = -1;
		int index2 = -1;
		for (int i = 0; i < N; i++) {
			if (v[i] == '1') {
				index1 = i;
				break;
			}
		}
		for (int i = N - 1; i > -1; i--) {
			if (v[i] == '1') {
				index2 = i;
				break;
			}
		}
		if (v[0] == '1') index1 = -1;
		if (v[N - 1] == '1') index2 = -1;
		if (index1 != -1 && index2 != -1 && index1 <= K && N - index2 - 1 <= K) {
			if (index1 == index2) {
				cout << t - 10 << endl;
			}
			else if (index1 + N - index2 -1 <= K) {
				cout << t - 11 << endl;
			}
			else {
				cout << t - 10 << endl;
			}
		}
		else if (index1 != -1 && index1 <= K) {
			if (index1 == N - 1) cout << t << endl;
			else cout << t - 1 << endl;
		}
		else if (index2 != -1 && N - index2 - 1 <= K) {
			if (index2 == 0) cout << t - 9 << endl;
			else cout << t - 10 << endl;
		}
		else {
			cout << t << endl;
		}
	}
}
