#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;
	A = A * 2;
	int dp[2001] = {0};
	int arr[2000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		arr[i] *= 2;
	}
	sort(arr, arr + N);
	dp[0] = A;
	for (int i = 1; i < N; i++) {
		int minimum = (arr[i] - arr[0]) / 2 * B + A;
		for (int j = 0; j < i; j++) {
			minimum = min(minimum, dp[j] + (arr[i] - arr[j + 1]) / 2 * B + A);
		}
		dp[i] = minimum;
	}
	if (dp[N - 1] % 2 == 0) cout << dp[N - 1] / 2 << endl;
	else cout << dp[N - 1] / 2 << ".5" << endl;
}

/*
Let dp[i] be the minimum cost to provide wifi for the first i cows
Loop over j < i to find dp[i]: minimum of dp[j] + cost to build one wifi station for cows j + 1 to i
*/