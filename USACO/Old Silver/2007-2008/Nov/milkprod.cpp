#include <bits/stdc++.h>
using namespace std;

struct Interval {
	int x;
	int y;
	int e;
};

int N, M, R;
vector<Interval> v;

bool comp(Interval a, Interval b) {
	return a.y < b.y;
}

int main() {
	cin >> N >> M >> R;
	int a, b, c;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back({a, b, c});
	}
	sort(v.begin(), v.end(), comp);
	int dp[1001] = {0};
	dp[0] = v[0].e;
	for (int i = 1; i < M; i++) {
		dp[i] = v[i].e;
		for (int j = i - 1; j > -1; j--) {
			if (v[j].y + R <= v[i].x) {
				dp[i] = max(dp[i], dp[j] + v[i].e);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= M; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}

/*
Dp[i] defined as the maximum milk when using the i th interval
Dp[i] can be calculated by looping through the previous solutions and checking if bessie has rested or not (provided that the intervals are sorted by endpoint)
Need to loop over array once to find answer as the answer might not use the last interval
Another way is to define dp[i] as the maximum milk at the i th interval, not necessarily using i
	Can bring complexity down to O(Nlog N) (but not necessary in this problem) by binary searching on the first interval where bessie is rested
*/