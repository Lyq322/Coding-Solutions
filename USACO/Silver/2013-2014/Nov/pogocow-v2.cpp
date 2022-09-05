#include <algorithm>
#include <bits/stdc++.h>
#include <ios>
using namespace std;

/*
For the O(N^3) solution, we can let dp[i][j] be defined as the maximum points when Bessie’s last move is from i to j
We can loop through i and j, then binary search for the previous index k that satisfies the distance between k and i is > distance between i and j
To lower the time complexity of this solution, we can use prefix sums to optimize it
Let maximum[i][j] be defined as the maximum element in the dp array in the ith column up until the jth row (row 0 through j)
Now we can calculate the dp in O(N^2)

For dp optimization, there is usually two ways
One is just a whole new dp formula, but there could also be a chance that you can optimize the current dp using techniques such as prefix sums and sliding window
*/

int main() {
	int N;
	cin >> N;
	pair<int, int> arr[1000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	int dp[1001][1001] = {{0}};
	for (int i = 0; i < N; i++) {
		dp[i + 1][i + 1] = arr[i].second;
	}
	int maximum[1001][1001] = {{0}};
	maximum[1][1] = dp[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (i == j) {
				maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
				continue;
			}
			int prev = arr[i - 1].first - (arr[j - 1].first - arr[i - 1].first);
			pair<int, int> p = {prev, 100000000};
			int index = upper_bound(arr, arr + N, p) - arr;
			dp[i][j] = arr[i - 1].second + arr[j - 1].second;
			maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
			if (index == N) {
				
			}
			else if (index == 0) {
				if (arr[0].first > prev) {
					continue;
				}
				else {
					dp[i][j] = max(dp[i][j], dp[1][i] + arr[j - 1].second);
				}
			}
			else {
				dp[i][j] = maximum[index][i] + arr[j - 1].second;
			}
			maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, dp[i][j]);
		}
	}

	// This time from right to left
	for (int i = 0; i < N; i++) {
		arr[i].first = 10000000 - arr[i].first;
	}
	sort(arr, arr + N);
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= N; j++) {
			dp[i][j] = 0;
			maximum[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		dp[i + 1][i + 1] = arr[i].second;
	}
	maximum[1][1] = dp[1][1];
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (i == j) {
				maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
				continue;
			}
			int prev = arr[i - 1].first - (arr[j - 1].first - arr[i - 1].first);
			pair<int, int> p = {prev, 100000000};
			int index = upper_bound(arr, arr + N, p) - arr;
			dp[i][j] = arr[i - 1].second + arr[j - 1].second;
			maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
			if (index == N) {
				
			}
			else if (index == 0) {
				if (arr[0].first > prev) {
					continue;
				}
				else {
					dp[i][j] = max(dp[i][j], dp[1][i] + arr[j - 1].second);
				}
			}
			else {
				dp[i][j] = maximum[index][i] + arr[j - 1].second;
			}
			maximum[i][j] = max(maximum[i - 1][j], dp[i][j]);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}