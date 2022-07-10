#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

int main() {
	int N;
	cin >> N;
	int a, b;
	pair<int, int> arr[100000];
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		arr[2 * i] = {a, 1};
		arr[2 * i + 1] = {b, -1};
	}
	sort(arr, arr + 2 * N, comp);
	int t = 0;
	int ans = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (arr[i].second == 1) {
			t++;
		}
		else {
			t--;
		}
		ans = max(ans, t);
	}
	cout << ans << endl;
}
