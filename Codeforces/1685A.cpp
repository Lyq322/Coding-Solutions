#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		vector<int> v;
		int a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
		}
		if (N % 2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		sort(v.begin(), v.end());
		int index = 0;
		int s = 0;
		bool c = false;
		for (int i = 1; i < N; i++) {
			if (v[index] == v[i]) {
				s++;
			}
			else {
				s++;
				if (s >= N / 2 && index != 0) {
					cout << "NO" << endl;
					c = true;
					break;
				}
				else if (s > N / 2 && index == 0) {
					cout << "NO" << endl;
					c = true;
					break;
				}
				s = 0;
				index = i;
			}
		}
		if (c) continue;
		if (s >= N / 2 && index != 0) {
			cout << "NO" << endl;
			continue;
		}
		else if (s > N / 2 && index == 0) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				cout << v[i / 2] << ' ';
			}
			else {
				cout << v[N / 2 + i / 2] << ' ';
			}
		}
		cout << endl;
	}
}
