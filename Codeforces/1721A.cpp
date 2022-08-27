#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		char arr[2][2];
		int c[26] = {0};
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				cin >> arr[i][j];
				c[arr[i][j] - 'a']++;
			}
		}
		vector<int> v;
		for (int i = 0; i < 26; i++) {
			if (c[i] != 0) {
				v.push_back(c[i]);
			}
		}
		sort(v.begin(), v.end());
		if (v.size() == 1) {
			cout << 0 << endl;
		}
		else if (v.size() == 2) {
			cout << 1 << endl;
		}
		else if (v.size() == 3) {
			cout << 2 << endl;
		}
		else {
			cout << 3 << endl;
		}
	}
}
