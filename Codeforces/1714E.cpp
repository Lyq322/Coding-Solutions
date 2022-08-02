#include <algorithm>
#include <bits/stdc++.h>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		int arr[200000];
		int maximum = 0;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			if (arr[i] % 2 == 1) arr[i] += arr[i] % 10;
			maximum = max(maximum, arr[i]);
		}
		bool b = false;
		if (maximum % 10 == 0) {
			for (int i = 0; i < N; i++) {
				if (arr[i] != maximum && arr[i] != maximum - 5) {
					cout << "NO" << endl;
					b = true;
					break;
				}
			}
			if (!b) cout << "YES" << endl;
			continue;
		}
		for (int i = 0; i < N; i++) {
			int temp = maximum - arr[i];
			temp = temp % 20;
			if (temp == 0) {
				continue;
			}
			if (arr[i] % 10 == 2) {
				if (temp == 2 || temp == 6 || temp == 14) {
				}
				else {
					cout << "NO" << endl;
					b = true;
					break;
				}
			}
			else if (arr[i] % 10 == 4) {
				if (temp == 4 || temp == 12 || temp == 18) {
				}
				else {
					cout << "NO" << endl;
					b = true;
					break;
				}
			}
			else if (arr[i] % 10 == 6) {
				if (temp == 6 || temp == 8 || temp == 12) {
				}
				else {
					cout << "NO" << endl;
					b = true;
					break;
				}
			}
			else if (arr[i] % 10 == 8) {
				if (temp == 8 || temp == 14 || temp == 16) {
				}
				else {
					cout << "NO" << endl;
					b = true;
					break;
				}
			}
			else {
				cout << "NO" << endl;
				b = true;
				break;
			}
		}
		if (!b) cout << "YES" << endl;
	}
}
