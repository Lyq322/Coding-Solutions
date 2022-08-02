// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int arr[200000];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		set<int> s;
		bool found = false;
		for (int i = N - 1; i > -1; i--) {
			if (s.find(arr[i]) == s.end()) {
				s.insert(arr[i]);
			}
			else {
				cout << i + 1 << endl;
				found = true;
				break;
			}
		}
		if (!found) {
			cout << 0 << endl;
		}
	}
}
