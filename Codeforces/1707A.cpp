#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		int test[100000];
		for (int i = 0; i < N; i++) {
			cin >> test[i];
		}
		reverse(test, test + N);
		int iq = 0;
		vector<int> ans;
		for (int i = 0; i < N; i++) {
			if (iq >= test[i]) ans.push_back(1);
			else {
				if (iq == M) ans.push_back(0);
				else {
					ans.push_back(1);
					iq++;
				}
			}
		}
		reverse(ans.begin(), ans.end());
		for (int i = 0; i < N; i++) cout << ans[i];
		cout << endl;
	}
}
