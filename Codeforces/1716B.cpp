#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		vector<int> v;
		for (int i = 0; i < N; i++) {
			v.push_back(i + 1);
		}
		cout << N << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << v[j] << ' ';
			}
			cout << endl;
			if (i != N - 1) swap(v[i], v[i + 1]);
		}
	}
}
