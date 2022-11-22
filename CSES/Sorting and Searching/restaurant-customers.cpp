#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	pair<int, int> arr[400000];
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[2 * i] = {a, 1};
		arr[2 * i + 1] = {b, -1};
	}
	sort(arr, arr + 2 * N);
	int ans = 0;
	int count = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (arr[i].second == 1) {
			count++;
			ans = max(ans, count);
		}
		else {
			count--;
		}
	}
	cout << ans << endl;
}
