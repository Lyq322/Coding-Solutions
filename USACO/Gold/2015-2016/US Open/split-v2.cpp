#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ifstream fin("split.in");
	ofstream fout("split.out");
	int N;
	fin >> N;
	pair<ll, ll> arr[50000];
	ll max_x = 0;
	ll max_y = 0;
	ll min_x = 1000000001;
	ll min_y = 1000000001;
	for (int i = 0; i < N; i++) {
		fin >> arr[i].first >> arr[i].second;
		max_x = max(max_x, arr[i].first);
		min_x = min(min_x, arr[i].first);
		max_y = max(max_y, arr[i].second);
		min_y = min(min_y, arr[i].second);
	}
	sort(arr, arr + N);
	ll minimum = -1;
	ll maximum = 0;
	ll left[50000];
	ll right[50000];
	ll up[50000];
	ll down[50000];
	for (int i = 0; i < N; i++) {
		if (minimum == -1 || arr[i].second < minimum) {
			minimum = arr[i].second;
		}
		maximum = max(maximum, arr[i].second);
		left[i] = (maximum - minimum) * (arr[i].first - arr[0].first);
	}
	minimum = -1;
	maximum = 0;
	for (int i = N - 1; i > -1; i--) {
		if (minimum == -1 || arr[i].second < minimum) {
			minimum = arr[i].second;
		}
		maximum = max(maximum, arr[i].second);
		right[i] = (maximum - minimum) * (arr[N - 1].first - arr[i].first);
	}
	sort(arr, arr + N, comp);
	minimum = -1;
	maximum = 0;
	for (int i = 0; i < N; i++) {
		if (minimum == -1 || arr[i].first < minimum) {
			minimum = arr[i].first;
		}
		maximum = max(maximum, arr[i].first);
		down[i] = (maximum - minimum) * (arr[i].second - arr[0].second);
	}
	minimum = -1;
	maximum = 0;
	for (int i = N - 1; i > -1; i--) {
		if (minimum == -1 || arr[i].first < minimum) {
			minimum = arr[i].first;
		}
		maximum = max(maximum, arr[i].first);
		up[i] = (maximum - minimum) * (arr[N - 1].second - arr[i].second);
	}
	ll ans = -1;
	for (int i = 0; i < N - 1; i++) {
		if (ans == -1 || ans > left[i] + right[i + 1]) {
			ans = left[i] + right[i + 1];
		}
		ans = min(ans, down[i] + up[i + 1]);
	}
	fout << (max_x - min_x) * (max_y - min_y) - ans << endl;
}
