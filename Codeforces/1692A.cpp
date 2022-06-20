#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int arr[4];
		for (int j = 0; j < 4; j++) {
			cin >> arr[j];
		}
		int ans = 0;
		for (int j = 1; j < 4; j++) {
			if (arr[0] < arr[j]) {
				ans++;
			}
		}
		cout << ans << endl;
	}
}
