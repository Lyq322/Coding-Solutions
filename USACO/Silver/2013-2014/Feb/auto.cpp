#include <bits/stdc++.h>

using namespace std;

int W, N;
vector<pair<string, string>> dict;

int main() {
	cin >> W >> N;
	string s;
	for (int i = 0; i < W; i++) {
		cin >> s;
		dict.push_back({s, to_string(i + 1)});
	}
	sort(dict.begin(), dict.end());
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a >> s;
		pair<string, string> temp = {s, "0"};
		int index = lower_bound(dict.begin(), dict.end(), temp) - dict.begin();
		index += a - 1;
		if (index >= W) {
			cout << -1 << endl;
		}
		else if (s.size() > dict[index].first.size()) {
			cout << -1 << endl;
		}
		else {
			bool b = true;
			for (int j = 0; j < s.size(); j++) {
				if (dict[index].first.at(j) != s.at(j)) {
					b = false;
					break;
				}
			}
			if (!b) {
				cout << -1 << endl;
			}
			else {
				cout << dict[index].second << endl;
			}
		}
	}
}

/*
Sort array of strings
Use lower_bound
O(N)
*/