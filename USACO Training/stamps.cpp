#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, N;
	cin >> K >> N;
	int arr[50];
	int maximum = 0;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	int dp[2000001] = {0};
	bool found = false;
	for (int i = 1; i <= maximum * K; i++) {
		for (int j = 0; j < N; j++) {
			if (i - arr[j] >= 0) {
				if (dp[i - arr[j]] + 1 <= K) {
					if (dp[i] == 0 || dp[i] > dp[i - arr[j]] + 1) dp[i] = dp[i - arr[j]] + 1;
				}
			}
		}
		if (dp[i] == 0) {
			found = true;
			cout << i - 1 << endl;
			break;
		}
	}
	if (!found) cout << maximum * K << endl;
}	

/*
Dp[i] defined as the minimum stamps it takes to get i, if possible
For each dp[i] in dp, loop over stamps to check previous columns in the dp
I think this is an easier version of Stamps (?)
*/