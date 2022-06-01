#include <bits/stdc++.h>

using namespace std;

int T, M, N, K;


void solve() {
	cin >> M >> N >> K;
	if (K >= M || K >= N) {
		cout << "YES\n";
		return;
	}
	vector<int> emails;
	vector<pair<int, int>> folders;
	int count[10001] = {0};
	for (int i = 0; i <= M; i++) {
		folders.push_back({-1, -1});
	}
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		emails.push_back(a);
		count[a]++;
	}
	for (int i = N - 1; i > -1; i--) {
		if (folders[emails[i]].second == -1) {
			folders[emails[i]].second = i;
		}
	}
	for (int i = 0; i < N; i++) {
		if (folders[emails[i]].first == -1) {
			folders[emails[i]].first = i;
		}
	}
	vector<int> skipped;
	int topFolder = 1;
	int bottomFolder = K;
	for (int i = 0; i < N; i++) {
		if (topFolder <= emails[i] && emails[i] <= bottomFolder) {
			count[emails[i]]--;
			for (int j = topFolder; j <= M; j++) {
				if (count[j] != 0) {
					topFolder = j;
					bottomFolder = topFolder + K - 1;
					break;
				}
			}
			if (bottomFolder >= M) {
				cout << "YES\n";
				return;
			}
		}
		else {
			skipped.push_back(emails[i]);
		}
	}
	cout << topFolder << ' ' << bottomFolder << endl;
	for (int i = 0; i < skipped.size(); i++) {
		cout << skipped[i] << ' ';
	}
	cout << endl;
	vector<int> skipped2;
	for (int i = skipped.size() - 1; i > -1; i--) {
		if (topFolder <= skipped[i] && skipped[i] <= bottomFolder) {
			count[skipped[i]]--;
			for (int j = topFolder; j <= M; j++) {
				if (count[j] != 0) {
					topFolder = j;
					bottomFolder = topFolder + K - 1;
					break;
				}
			}
			if (bottomFolder >= M) {
				cout << "YES\n";
				return;
			}
		}
		else {
			skipped2.push_back(skipped[i]);
		}
	}
	for (int i = skipped2.size(); i > -1; i--) {
		if (topFolder <= skipped2[i] && skipped2[i] <= bottomFolder) {
			count[skipped2[i]]--;
			for (int j = topFolder; j <= M; j++) {
				if (count[j] != 0) {
					topFolder = j;
					bottomFolder = topFolder + K - 1;
					break;
				}
			}
			if (bottomFolder >= M) {
				cout << "YES\n";
				return;
			}
		}
		else {
			cout << "NO\n";
			return;
		}
	}
}


int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}
