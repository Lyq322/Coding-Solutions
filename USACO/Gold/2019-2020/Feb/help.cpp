#include <bits/stdc++.h>
using namespace std;

int N;
pair<int, int> intervals[100000];
int line[200001] = {0};
int ps[200001] = {0};
long long two[100000] = {0};

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		intervals[i] = {a, b};
		line[a]++;
		line[b]--;
	}
	ps[0] = line[0];
	for (int i = 1; i <= 2 * N; i++) {
		ps[i] = ps[i - 1] + line[i];
	}
	two[0] = 1;
	for (int i = 1; i < N; i++) {
		two[i] = (two[i - 1] * 2) % 1000000007;
	}
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		ans = (ans + two[N - ps[intervals[i].first - 1] - 1]) % 1000000007;
	}
	cout << ans << endl;
}
