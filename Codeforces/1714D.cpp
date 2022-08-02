#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	cin.ignore();
	while (T--) {
		string t, s;
		int N;
		string arr[10];
		getline(cin, t);
		cin >> N;
		cin.ignore();
		for (int i = 0; i < N; i++) {
			getline(cin, s);
			arr[i] = s;
		}
		vector<int> ss[10];
		for (int i = 0; i < N; i++) {
			if (t.size() < arr[i].size()) continue;
			for (int j = 0; j < t.size() - arr[i].size() + 1; j++) {
				bool b = true;
				for (int k = j; k < j + arr[i].size(); k++) {
					if (t.at(k) != arr[i].at(k - j)) {
						b = false;
						break;
					}
				}
				if (b) {
					ss[i].push_back(j);
				}
			}
		}
		int i = 0;
		int ans = 0;
		bool print = true;
		vector<pair<int, int>> v_ans;
		while (i < t.size()) {
			int maximum = -1;
			pair<int, int> max_index = {-1, -1};
			bool found = false;
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < ss[j].size(); k++) {
					if (ss[j][k] <= i && ss[j][k] + (int) arr[j].size() - 1 >= i) {
						if (maximum < ss[j][k] + (int) arr[j].size() - 1) {
							maximum = ss[j][k] + (int) arr[j].size() - 1;
							max_index = {j, ss[j][k]};
							found = true;
						}
					}
				}
			}
			if (!found) {
				cout << -1 << endl;
				print = false;
				break;
			}
			v_ans.push_back(max_index);
			i = maximum + 1;
			ans++;
		}
		if (print) {
			cout << ans << endl;
			for (int j = 0; j < v_ans.size(); j++) {
				cout << v_ans[j].first + 1 << ' ' << v_ans[j].second + 1 << endl;
			}
		}
	}
}
