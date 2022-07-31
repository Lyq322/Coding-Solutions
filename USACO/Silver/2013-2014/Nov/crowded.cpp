#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;
	pii arr[100000];
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	multiset<int> s;
	queue<int> q;
	int crowded[100000] = {0};
	for (int i = 0; i < N; i++) {
		q.push(i);
		s.insert(arr[i].second);
		while (!q.empty()) {
			if (arr[q.front()].first + M < arr[i].first) {
				s.erase(s.find(arr[q.front()].second));
				q.pop();
			}
			else break;
		}
		if (*prev(s.end()) >= 2 * arr[i].second) crowded[i]++;
	}
	s.clear();
	while (!q.empty()) 
		q.pop();
	for (int i = N - 1; i > -1; i--) {
		q.push(i);
		s.insert(arr[i].second);
		while (!q.empty()) {
			if (arr[q.front()].first + M < arr[i].first) {
				s.erase(s.find(arr[q.front()].second));
				q.pop();
			}
			else break;
		}
		if (*prev(s.end()) >= 2 * arr[i].second) crowded[i]++;
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (crowded[i] == 2) ans++;
	}
	cout << ans << endl;
}
