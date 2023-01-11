#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

multiset<pii> s;
int same = 0;

int solve(int width) {
	auto it1 = s.begin();
	auto it2 = next(s.begin());
	int starts = 0;
	int ends = 0;
	if (it1 -> second == 0) starts++;
	else if (it1 -> second == 2) ends++;
	if (it2 -> second == 0) starts++;
	else if (it2 -> second == 2) ends++;
	int count = 0;
	while (it1 != s.end() && it2 != s.end()) {
		if (starts > 0 && ends > 0) {
			int y = it2 -> first - it1 -> first;
			if (y > width) {
				if (it1 -> second == 0) starts--;
				else if (it1 -> second == 2) ends--;
				it1++;
			}
			else {
				if (y == width) {
					same++;
				}
				if (it1 == s.begin()) {
					count++;
				}
				else if (it2 == prev(s.end())) {
					count++;
				}
				else {
					int total = next(it2) -> first - prev(it1) -> first - 2;
					if (total >= width) {
						count++;
					}
				}
				if (it2 == prev(s.end()) || next(it2) -> first - it1 -> first > width) {
					if (it1 -> second == 0) starts--;
					else if (it1 -> second == 2) ends--;
					it1++;
					continue;
				}
				it2++;
				if (it2 != s.end()) {
					if (it2 -> second == 0) starts++;
					else if (it2 -> second == 2) ends++;
				}
			}
		}
		else {
			int y = it2 -> first - it1 -> first;
			if (y > width) {
				if (it1 -> second == 0) starts--;
				else if (it1 -> second == 2) ends--;
				it1++;
			}
			else {
				if (it2 == prev(s.end()) || next(it2) -> first - it1 -> first > width) {
					if (it1 -> second == 0) starts--;
					else if (it1 -> second == 2) ends--;
					it1++;
					continue;
				}
				it2++;
				if (it2 != s.end()) {
					if (it2 -> second == 0) starts++;
					else if (it2 -> second == 2) ends++;
				}
			}
		}
	}
	return count;
}

int main() {
	int N;
	cin >> N;
	pii arr[200];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	int i = 0;
	//pair<y-coord, type (0, 1, 2)>
	// 0 = start, 1 = middle, 2 = end
	int ans = 0;
	while (i < N) {
		s.insert({arr[i].second, 0});
		if (i == N - 1 || arr[i + 1].first != arr[i].first) {
			int j = i + 1;
			while (j < N) {
				s.insert({arr[j].second, 2});
				if (j == N - 1 || arr[j + 1].first != arr[j].first) {
					int r = solve(arr[j].first - arr[i].first);
					ans += r;
					for (int k = j; k > -1; k--) {
						s.erase(s.find({arr[k].second, 2}));
						s.insert({arr[k].second, 1});
						if (k == 0 || arr[k - 1].first != arr[k].first) {
							break;
						}
					}
				}
				j++;
			}
			s.clear();
		}
		i++;
	}
	for (int i = 0; i < N; i++) {
		int temp = arr[i].first;
		arr[i].first = arr[i].second;
		arr[i].second = temp;
	}
	sort(arr, arr + N);
	i = 0;
	while (i < N) {
		s.insert({arr[i].second, 0});
		if (i == N - 1 || arr[i + 1].first != arr[i].first) {
			int j = i + 1;
			while (j < N) {
				s.insert({arr[j].second, 2});
				if (j == N - 1 || arr[j + 1].first != arr[j].first) {
					int r = solve(arr[j].first - arr[i].first);
					ans += r;
					for (int k = j; k > -1; k--) {
						s.erase(s.find({arr[k].second, 2}));
						s.insert({arr[k].second, 1});
						if (k == 0 || arr[k - 1].first != arr[k].first) {
							break;
						}
					}
				}
				j++;
			}
			s.clear();
		}
		i++;
	}
	cout << ans + N + 1 - same / 2 << endl;
}
