#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	string spot[500];
	string plain[500];
	string s;
	cin.ignore();
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		spot[i] = s;
	}
	for (int i = 0; i < N; i++) {
		getline(cin, s);
		plain[i] = s;
	}
	int ans = 1000;
	for (int i = 0; i < M - 1; i++) {
		string ss1[500];
		for (int j = 0; j < N; j++) {
			ss1[j] = "";
		}
		string ss2[500];
		for (int j = 0; j < N; j++) {
			ss2[j] = "";
		}
		for (int j = i; j < M; j++) {
			if (j - i + 1 >= ans) continue;
			set<string> s_str;
			vector<string> v;
			for (int k = 0; k < N; k++) {
				ss1[k] += spot[k].at(j);
				ss2[k] += plain[k].at(j);
				s_str.insert(ss1[k]);
				v.push_back(ss2[k]);
			}
			bool b = true;
			for (int k = 0; k < v.size(); k++) {
				auto it = s_str.lower_bound(v[k]);
				if (it != s_str.end() && *it == v[k]) {
					b = false;
					break;
				}
			}
			if (b) {
				ans = min(ans, j - i + 1);
			}
		}
	}
	cout << ans << endl;
}

// Timeout on t6,7,10