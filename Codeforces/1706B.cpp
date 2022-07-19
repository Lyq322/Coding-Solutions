#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int z = 0; z < T; z++) {
		int N;
		int arr[100000];
		cin >> N;
		vector<vector<int>> colors;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
			arr[i]--;
			colors.push_back({});
		}
		for (int i = 0; i < N; i++) {
			colors[arr[i]].push_back(i);
		}
		for (int i = 0; i < N; i++) {
			if (colors[i].size() == 0) {
				cout << 0 << ' ';
				continue;
			}
			bool even;
			if (colors[i][0] % 2 == 0) even = true;
			else even = false;
			int ans = 1;
			for (int j = 1; j < colors[i].size(); j++) {
				if (colors[i][j] % 2 == 0 && even == false) {
					even = true;
					ans++;
				}
				else if (colors[i][j] % 2 == 1 && even == true) {
					even = false;
					ans++;
				}
			}
			cout << ans << ' ';
		}
		cout << endl;
	}
}
