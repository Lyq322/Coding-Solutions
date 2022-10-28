#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

// Binary search on answer

int N;
pii arr[1000];

bool comp(pii a, pii b) {
	return a.second < b.second;
}

bool check(int t) {
	for (int i = 0; i < N; i++) {
		if (t > arr[i].second - arr[i].first) return false;
		t += arr[i].first;
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, comp);
	int l = 0;
	int r = 1000000;
	int m;
	bool found = false;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == 1000000 || !check(m + 1))) {
			cout << m << endl;
			found = true;
			break;
		}
		else if (check(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	if (!found) cout << -1 << endl;
}
