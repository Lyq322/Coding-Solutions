#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N;
	cin >> N;
	pair<int, int> cows[1000];
	for (int i = 0; i < N; i++) {
		cin >> cows[i].first >> cows[i].second;
	}
	int ans = 10000;
	sort(cows, cows + N);
	for (int i = 1; i < N; i++) {
		vector<int> v1;
		vector<int> v2;
		for (int j = 0; j < i; j++) {
			v1.push_back(cows[j].second);
		}
		for (int j = i; j < N; j++) {
			v2.push_back(cows[j].second);
		}
		sort(v1.begin(), v1.end());
		sort(v2.begin(), v2.end());
		for (int j = 0; j < N; j++) {
			int vertical = cows[j].second + 1;
			int index1 = lower_bound(v1.begin(), v1.end(), vertical) - v1.begin();
			int index2 = lower_bound(v2.begin(), v2.end(), vertical) - v2.begin();
			ans = min(ans, max(max(index1, (int) v1.size() - index1), max(index2, (int) v2.size() - index2)));
		}
	}
	cout << ans << endl;
}

// Loop through all possible vertical / horizontal fences, and use lower/upper bound to find out the number of cows in each quadrant