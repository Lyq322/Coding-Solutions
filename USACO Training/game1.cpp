#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
int arr[100];
pii dp[101][101];

pii solve2(int i, int j);

pii solve1(int i, int j) {
	if (dp[i][j].first != -1) {
		return dp[i][j];
	}
	if (i == j) {
		dp[i][j] = {arr[i], 0};
	}
	else if (i + 1 == j) {
		if (arr[i] > arr[j]) {
			dp[i][j] = {arr[i], 0};
			dp[i + 1][j] = {arr[j], 0};
		}
		else {
			dp[i][j] = {arr[j], 1};
			dp[i][j - 1] = {arr[i], 0};
		}
	}
	else {
		int side = solve2(i + 1, j).second;
		if (side == 0) {
			dp[i][j] = {arr[i] + solve1(i + 2, j).first, 0};
		}
		else {
			dp[i][j] = {arr[i] + solve1(i + 1, j - 1).first, 0};
		}
		side = solve2(i, j - 1).second;
		if (side == 0) {
			if (dp[i][j].first < arr[j] + solve1(i + 1, j - 1).first) dp[i][j] = {arr[j] + solve1(i + 1, j - 1).first, 1};
		}
		else {
			if (dp[i][j].first < arr[j] + solve1(i, j - 2).first) dp[i][j] = {arr[j] + solve1(i, j - 2).first, 1};
		}
	}
	return dp[i][j];
}

pii solve2(int i, int j) {
	if (dp[i][j].first != -1) {
		return dp[i][j];
	}
	if (i == j) {
		dp[i][j] = {arr[i], 0};
	}
	else if (i + 1 == j) {
		if (arr[i] > arr[j]) {
			dp[i][j] = {arr[i], 0};
			dp[i + 1][j] = {arr[j], 0};
		}
		else {
			dp[i][j] = {arr[j], 1};
			dp[i][j - 1] = {arr[i], 0};
		}
	}
	else {
		int side = solve1(i + 1, j).second;
		if (side == 0) {
			dp[i][j] = {arr[i] + solve2(i + 2, j).first, 0};
		}
		else {
			dp[i][j] = {arr[i] + solve2(i + 1, j - 1).first, 0};
		}
		side = solve1(i, j - 1).second;
		if (side == 0) {
			if (dp[i][j].first < arr[j] + solve2(i + 1, j - 1).first) dp[i][j] = {arr[j] + solve2(i + 1, j - 1).first, 1};
		}
		else {
			if (dp[i][j].first < arr[j] + solve2(i, j - 2).first) dp[i][j] = {arr[j] + solve2(i, j - 2).first, 1};
		}
	}
	return dp[i][j];
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = {-1, -1};
		}
	}
	cout << solve1(0, N - 1).first << ' ';
	if (dp[0][N - 1].second == 0) {
		cout << dp[1][N - 1].first << endl;
	}
	else {
		cout << dp[0][N - 2].first << endl;
	}
}

// Define dp[i][j] as the maximum points you can get from the subarray from index i to j