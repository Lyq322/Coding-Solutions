#include <bits/stdc++.h>
using namespace std;

/*
Give each cow a value: if the cow is spotted, val = -1, and if the cow is white, val = 1
Notice that the sum of the values of a range of cows that satisfies the condition is nonnegative
This reminds us of prefix sum, as it can help us quickly calculate the sum of the values from index i to j
Create a ps[i] array
Notice that for each element ps[i] in ps, we want to find the largest j where j > i and ps[j] > ps[i]. Also make sure that i and j have different parities
Also notice that if ps[i] < ps[j] and i < j, then we can essentially “remove” ps[i] since it will not affect the result of the previously mentioned queries. This only works if i and j have the same parity
This means we can work backwards, starting from right to left, and using a vector/arraylist where we only add elements in ps that will not disturb strictly increasing property of the vector/arraylist
Next, we can binary search on the vector/arraylist to find the largest j
****Parity****
*/

bool comp(pair<int, int> p1, pair<int, int> p2) {
	return p1 > p2;
}

int main() {
	int N;
	cin >> N;
	pair<int, int> arr[100000];
	char c;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first;
		cin >> c;
		if (c == 'W') {
			arr[i].second = 1;
		}
		else arr[i].second = -1;
	}
	sort(arr, arr + N);
	int ps[100001] = {0};
	for (int i = 0; i < N; i++) {
		ps[i + 1] = ps[i] + arr[i].second;
	}
	vector<pair<int, int>> v;
	int ans = 0;
	int s;
	if (N % 2 == 0) {
		s = N;
	}
	else {
		s = N - 1;
	}
	for (int i = s; i > 1; i = i - 2) {
		if (v.size() == 0 || v[v.size() - 1].first < ps[i]) {
			v.push_back({ps[i], i - 1});
		}
		pair<int, int> p = {ps[i - 2], 0};
		int index = lower_bound(v.begin(), v.end(), p) - v.begin();
		if (index == v.size()) {
			continue;
		}
		else {
			index = v[index].second;
		}
		ans = max(ans, arr[index].first - arr[i - 2].first);
	}
	v.clear();
	if (N % 2 == 0) {
		s = N - 1;
	}
	else s = N;
	for (int i = s; i > 2; i = i - 2) {
		if (v.size() == 0 || v[v.size() - 1].first < ps[i]) {
			v.push_back({ps[i], i - 1});
		}
		pair<int, int> p = {ps[i - 2], 0};
		int index = lower_bound(v.begin(), v.end(), p) - v.begin();
		if (index == v.size()) {
			continue;
		}
		else {
			index = v[index].second;
		}
		ans = max(ans, arr[index].first - arr[i - 2].first);
	}
	cout << ans << endl;
}
