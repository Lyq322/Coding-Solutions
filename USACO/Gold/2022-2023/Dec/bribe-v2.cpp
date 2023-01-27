#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

// Full solution O(N * (A + B))

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
	// dp[index][mooney][ice cream]
	ll dp1[2][2001] = {{0}};
	ll dp2[2][2001] = {{0}};
	for (int i = 0; i < N; i++) {
		// ice cream = 0
		for (int j = 0; j <= A; j++) {
			if (j - cows[i].m >= 0) dp2[(i + 1) % 2][j - cows[i].m] = max(dp2[(i + 1) % 2][j - cows[i].m], dp2[i % 2][j] + cows[i].p);
			dp2[(i + 1) % 2][j] = max(dp2[(i + 1) % 2][j], dp2[i % 2][j]);
		}
		// mooney = A
		for (int j = 0; j <= B; j++) {
			if (j >= cows[i].i * cows[i].m) {
				int left = j - cows[i].i * cows[i].m;
				dp1[(i + 1) % 2][left] = max(dp1[(i + 1) % 2][left], dp1[i % 2][j] + cows[i].p);
			}
			else {
				int discount = j / cows[i].i;
				if (A - (cows[i].m - discount) >= 0) {
					dp2[(i + 1) % 2][A - (cows[i].m - discount)] = max(dp2[(i + 1) % 2][A - (cows[i].m - discount)], dp1[i % 2][j] + cows[i].p);
				}
			}
			dp1[(i + 1) % 2][j] = max(dp1[(i + 1) % 2][j], dp1[i % 2][j]);
		}
	}
	ll ans = 0;
	for (int j = 0; j <= A; j++) {
		ans = max(ans, dp1[N % 2][j]);
	}
	for (int j = 0; j <= B; j++) {
		ans = max(ans, dp2[N % 2][j]);
	}
	cout << ans << endl;
}
