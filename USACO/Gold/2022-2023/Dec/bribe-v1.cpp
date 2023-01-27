#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// Partial (timeout on last subtask) - O(N*A*B)

struct Cow {
	int p;
	int m;
	int i;
};

bool comp(Cow a, Cow b) {
	return a.i < b.i;
}

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	int a, b, c;
	Cow cows[2000];
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		cows[i] = {a, b, c};
	}
	sort(cows, cows + N, comp);
	ll dp[2][2001][2001] = {{{0}}};
	// dp[index][mooney][ice cream]
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= A; j++) {
			for (int k = 0; k <= B; k++) {
				int still_need, cones_left;
				if (k / cows[i].i >= cows[i].m) {
					cones_left = k - cows[i].i * cows[i].m;
					still_need = 0;
				}
				else {
					cones_left = k % cows[i].i;
					still_need = cows[i].m - k / cows[i].i;
				}
				if (j - still_need >= 0) {
					dp[(i + 1) % 2][j - still_need][cones_left] = max(dp[(i + 1) % 2][j - still_need][cones_left], dp[i % 2][j][k] + cows[i].p);
				}
				dp[(i + 1) % 2][j][k] = max(dp[(i + 1) % 2][j][k], dp[i % 2][j][k]);
			}
		}
	}
	ll ans = 0;
	for (int j = 0; j <= A; j++) {
		for (int i = 0; i <= B; i++) {
			ans = max(ans, dp[N % 2][j][i]);
		}
	}
	cout << ans << endl;
}
