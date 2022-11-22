#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	int arr[200000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int i = 0;
	int j = N - 1;
	int ans = 0;
	while (i <= j) {
		if (i == j) {
			ans++;
			break;
		}
		if (arr[i] + arr[j] <= M) {
			i++;
			j--;
			ans++;
		}
		else {
			j--;
			ans++;
		}
	}
	cout << ans << endl;
}
