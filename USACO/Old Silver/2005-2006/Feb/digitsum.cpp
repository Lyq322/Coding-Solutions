#include <bits/stdc++.h>
using namespace std;

int N, K;
bool visited[10] = {0};
int binomial[10][10] = {0};
bool found = false;

void solve(string s) {
	if (found) return;
	if (s.size() == N) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			int a = s.at(i) - '0';
			ans += a * binomial[N - 1][i];
		}
		if (ans == K) {
			for (int i = 0; i < N; i++) {
				cout << s.at(i) << ' ';
			}
			cout << endl;
			found = true;
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i + 1]) {
			visited[i + 1] = true;
			char c = '0' + i + 1;
			solve(s + c);
			visited[i + 1] = false;
		}
	}
}

int main() {
	cin >> N >> K;
	binomial[0][0] = 1;
	for (int i = 1; i < N; i++) {
		binomial[i][0] = 1;
		binomial[i][i] = 1;
		for (int j = 1; j < i; j++) {
			binomial[i][j] = binomial[i - 1][j] + binomial[i - 1][j - 1];
		}
	}
	solve("");
}
//Only 10! possibilities, so we can test every single one