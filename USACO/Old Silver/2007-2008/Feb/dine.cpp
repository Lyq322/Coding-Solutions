#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	vector<int> arr;
	cin >> N;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		arr.push_back(a);
	}
	int dp1[30001][4];
	int dp2[30001][4];
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 4; j++) {
			dp1[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	dp1[0][1] = 0;
	dp1[0][2] = 0;
	dp1[0][3] = 0;
	dp2[0][1] = 0;
	dp2[0][2] = 0;
	dp2[0][3] = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 1; k <= j; k++) {
				if (j == arr[i - 1]) {
					if (dp1[i][j] == -1 || dp1[i][j] > dp1[i - 1][k]) dp1[i][j] = dp1[i - 1][k];
				}
				else {
					if (dp1[i][j] == -1 || dp1[i][j] > dp1[i - 1][k] + 1) dp1[i][j] = dp1[i - 1][k] + 1;
				}
			}
		}
	}
	reverse(arr.begin(), arr.end());
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < 4; j++) {
			for (int k = 1; k <= j; k++) {
				if (j == arr[i - 1]) {
					if (dp2[i][j] == -1 || dp2[i][j] > dp2[i - 1][k]) dp2[i][j] = dp2[i - 1][k];
				}
				else {
					if (dp2[i][j] == -1 || dp2[i][j] > dp2[i - 1][k] + 1) dp2[i][j] = dp2[i - 1][k] + 1;
				}
			}
		}
	}
	cout << min(min(min(min(min(dp1[N][1], dp1[N][2]), dp1[N][3]), dp2[N][1]), dp2[N][2]), dp2[N][3]) << endl;
}

/*
Calculate increasing and decreasing separately
1D dp array to store the minimum changes for the first i cow
However, this won’t take in account what the current cow is and if the current cow needs to be changed
⇒ 2D dp array dp[i][j] defined as the minimum changes for the first i cow when the ith cow is j so that all cows are increasing/decreasing
*/