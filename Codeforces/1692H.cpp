#include <bits/stdc++.h>
using namespace std;

int T, N;
vector<vector<int>> v;
int a1, a2, a3;

int solve(int index) {
	pair<int, int> dp[2];
	dp[0] = {v[index][0], 1};
	int maximum = 0;
	int prev = 0;
	int cur = 0;
	for (int i = 1; i < v[index].size(); i++) {
		if (dp[(i - 1) % 2].second - (v[index][i] - v[index][i - 1] - 1) + 1 > 1) {
			dp[i % 2] = {dp[(i - 1) % 2].first, dp[(i - 1) % 2].second - (v[index][i] - v[index][i - 1] - 1) + 1};
		}
		else {
			dp[i % 2] = {v[index][i], 1};
		}
		if (dp[i % 2].second > maximum) {
			maximum = dp[i % 2].second;
			prev = dp[i % 2].first;
			cur = v[index][i];
		}
	}
	if (dp[(v[index].size() - 1) % 2].second > maximum) {
		maximum = dp[(v[index].size() - 1) % 2].second;
		prev = dp[(v[index].size() - 1) % 2].first;
		cur = v[index][v[index].size() - 1];
	}
	a1 = maximum;
	a2 = prev;
	a3 = cur;
	return maximum;
}

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		v.clear();
		cin >> N;
		int arr[200000];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		map<int, int> m;
		int index = 0;
		int reverse[200000];
		for (int i = 0; i < N; i++) {
			if (m.find(arr[i]) == m.end()) {
				m[arr[i]] = index;
				reverse[index] = arr[i];
				v.push_back({});
				v[index].push_back(i);
				index++;
			}
			else {
				v[m[arr[i]]].push_back(i);
			}
		}
		int ans = 0;
		int a, b, c;
		for (int i = 0; i < index; i++) {
			int s = solve(i);
			if (s > ans) {
				ans = s;
				a = a2;
				b = a3;
				c = i;
			}
		}
		cout << reverse[c] << ' ' << a + 1 << ' ' << b + 1 << endl;
	}
}

/*
The maximum points when choosing a can be calculated in O(N) time, where N is the number of the chosen number a in the array
This means the total time complexity is also O(N), where N is the array size
To calculate maximum points, we can use a dp/sliding window-ish approach
l, r pointers
If moving the r pointer makes the total less than the original point (1), then we start over
Need to keep track of the start and end position too
*/