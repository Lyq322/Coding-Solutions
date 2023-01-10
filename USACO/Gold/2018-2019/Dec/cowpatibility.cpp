#include <bits/stdc++.h>
using namespace std;

// Timeout 2-3 testcases (8/9/10)

struct Flavor {
	int n;
	int f[5];
};

int N;
map<Flavor, int> m;
int arr[50000][5];

bool operator<(Flavor a, Flavor b) {
	if (a.n != b.n) return a.n < b.n;
	for (int i = 0; i < 5; i++) {
		if (a.f[i] != b.f[i]) {
			return a.f[i] < b.f[i];
		}
	}
	return false;
}

void solve(int pos, string s) {
	if (s.size() == 5) {
		vector<int> v;
		int count = 0;
		for (int i = 0; i < 5; i++) {
			if (s.at(i) == '1') {
				count++;
				v.push_back(arr[pos][i]);
			}
		}
		for (int i = 0; i < 5; i++) {
			if (s.at(i) == '0') {
				v.push_back(-1);
			}
		}
		Flavor f = {count, {v[0], v[1], v[2], v[3], v[4]}};
		if (m.find(f) == m.end()) {
			m[f] = 1;
		}
		else {
			m[f]++;
		}
		return;
	}
	solve(pos, s + '0');
	solve(pos, s + '1');
}

int main() {
	ifstream fin("cowpatibility.in");
	ofstream fout("cowpatibility.out");
	fin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 5; j++) {
			fin >> arr[i][j];
		}
		sort(arr[i], arr[i] + 5);
	}
	for (int i = 0; i < N; i++) {
		solve(i, "");
	}
	int ans = 0;
	for (auto it = m.begin(); it != m.end(); it++) {
		int len = (it -> first).n;
		int count = it -> second;
		if (len == 0) continue;
		else if (len % 2 == 0) {
			ans -= count * (count - 1) / 2;
		}
		else {
			ans += count * (count - 1) / 2;
		}
	}
	fout << N * (N - 1) / 2 - ans << endl;
}
