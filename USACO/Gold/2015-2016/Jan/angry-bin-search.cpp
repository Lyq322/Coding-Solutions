#include <bits/stdc++.h>
using namespace std;

// Sad 8/10 :(
// Binary search on radius -> binary search on position

vector<int> v;

bool checkl(int radius, int range) {
	int index = lower_bound(v.begin(), v.end(), range) - v.begin();
	if (index == 0) return true;
	int start;
	if (index == (int) v.size()) {
		start = (int) v.size() - 1;
	}
	else {
		if (v[index] == range) {
			start = index;
		}
		else {
			start = index - 1;
		}
	}
	int p1 = range;
	int p2 = start;
	int cur_r = radius;
	int prev = -1;
	while (p2 >= 0 && cur_r >= 0) {
		if (prev == p2) break;
		prev = p2;
		int newp1 = p1;
		while (p2 >= 0) {
			if (p1 - v[p2] <= cur_r) {
				newp1 = v[p2];
				p2--;
			}
			else {
				break;
			}
		}
		p1 = newp1;
		cur_r -= 2;
	}
	if (p2 < 0) return true;
	else return false;
}

bool checkr(int radius, int range) {
	int index = lower_bound(v.begin(), v.end(), range) - v.begin();
	if (index == (int) v.size()) return true;
	int p1 = range;
	int p2 = index;
	int cur_r = radius;
	int prev = -1;
	while (p2 < (int) v.size() && cur_r >= 0) {
		if (prev == p2) break;
		prev = p2;
		int newp1 = p1;
		while (p2 < v.size()) {
			if (v[p2] - p1 <= cur_r) {
				newp1 = v[p2];
				p2++;
			}
			else {
				break;
			}
		}
		p1 = newp1;
		cur_r -= 2;
	}
	if (p2 >= (int) v.size()) return true;
	else return false;
}

bool bin_on_R(int radius) {
	int l = 0;
	int r = 1000000000;
	int m;
	int lb = -1;
	int ub = -1;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (checkl(radius, m) && (m == 1000000000 || !checkl(radius, m + 1))) {
			lb = m;
			break;
		}
		else if (checkl(radius, m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
	l = 0;
	r = 1000000000;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (checkr(radius, m) && (m == 0 || !checkr(radius, m - 1))) {
			ub = m;
			break;
		}
		else if (checkr(radius, m)) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	if (lb != -1 && ub != -1 && lb >= ub) return true;
	return false;
}

int main() {
	int N;
	cin >> N;
	v.assign(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		v[i] = v[i] * 2;
	}
	sort(v.begin(), v.end());
	int l = 0;
	int r = 1000000;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (bin_on_R(m) && (m == 0 || !bin_on_R(m - 1))) {
			cout << fixed << setprecision(1) << (double) m / 2 << endl;
			break;
		}
		else if (bin_on_R(m)) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}
