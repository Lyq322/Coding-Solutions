#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		string s1, s2;
		cin.ignore();
		getline(cin, s1);
		getline(cin, s2);
		if (s1.at(0) != s2.at(0) || s1.at(N - 1) != s2.at(N - 1)) {
			cout << -1 << endl;
			continue;
		}

		vector<pair<int, int>> v1;
		vector<pair<int, int>> v2;

		int start = 0;
		for (int i = 0; i < N; i++) {
			if (s1[i] != '1') break;
			start++;
		}
		if (start != 0) v1.push_back({0, start - 1});
		int end = N - 1;
		for (int i = N - 1; i > -1; i--) {
			if (s1[i] != '1') break;
			end--;
		}
		if (end != N - 1 && end != -1) v1.push_back({end + 1, N - 1});
		bool b = true;
		int prev = 0;
		while (start <= end) {
			if (s1[start] == '0') {
				if (!b) {
					b = true;
					v1.push_back({prev, start - 1});
				}
			}
			else if (b) {
				b = false;
				prev = start;
			}
			start++;
		}

		start = 0;
		for (int i = 0; i < N; i++) {
			if (s2[i] != '1') break;
			start++;
		}
		if (start != 0) v2.push_back({0, start - 1});
		end = N - 1;
		for (int i = N - 1; i > -1; i--) {
			if (s2.at(i) != '1') {
				break;
			}
			end--;
		}
		if (end != N - 1 && end != -1) v2.push_back({end + 1, N - 1});
		b = true;
		while (start <= end) {
			if (s2[start] == '0') {
				if (!b) {
					b = true;
					v2.push_back({prev, start - 1});
				}
			}
			else if (b) {
				b = false;
				prev = start;
			}
			start++;
		}
		if (v1.size() != v2.size()) {
			cout << -1 << endl;
			continue;
		}
		long long ans = 0;
		for (int i = 0; i < v1.size(); i++) {
			ans += abs(v1[i].first - v2[i].first) + abs(v1[i].second - v2[i].second);
		}
		cout << ans << endl;
	}
}
