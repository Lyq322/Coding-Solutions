#include <bits/stdc++.h>

using namespace std;

int T, N;
vector<int> num;

bool check(int a, int b, int c) {
	set<int> s = {a, b, c, a+b, a+c, b+c, a+b+c};
	for (int i = 0; i < N; i++) {
		if (s.find(num[i]) != s.end()) s.erase(s.find(num[i]));
		else return false;
	}
	return true;
}

void solve() {
	cin >> N;
	int a;
	num.clear();
	for (int i = 0; i < N; i++) {
		cin >> a;
		num.push_back(a);
	}
	set<int> possible;
	for (int i = 0; i < N; i++) {
		possible.insert(num[i]);
		for (int j = 0; j < N; j++) {
			if (num[i] - num[j] > 0) {
				possible.insert(num[i] - num[j]);
			}
		}
	}
	int ans = 0;
	for (auto A : possible) {
		for (auto B : possible) {
			for (auto C : possible) {
				if (A <= B && B <= C && check(A, B, C)) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		solve();
	}
}
