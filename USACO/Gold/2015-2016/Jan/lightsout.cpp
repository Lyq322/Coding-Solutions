#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
pii arr[200];

int next_dir(int i) {
	if (arr[(i + 1) % N].second > arr[i].second && arr[(i + 2) % N].first > arr[(i + 1) % N].first) {
		return 0;
	}
	else if (arr[(i + 1) % N].first > arr[i].first && arr[(i + 2) % N].second < arr[(i + 1) % N].second) {
		return 0;
	}
	else if (arr[(i + 2) % N].second > arr[(i + 1) % N].second && arr[i].first > arr[(i + 1) % N].first) {
		return 0;
	}
	else if (arr[i].second > arr[(i + 1) % N].second && arr[(i + 1) % N].first > arr[(i + 2) % N].first) {
		return 0;
	}
	else return 1;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	int dir;
	vector<int> v;
	v.push_back(2);
	for (int i = 0; i < N; i++) {
		dir = next_dir(i);
		int len = abs(arr[i].first - arr[(i + 1) % N].first) + abs(arr[i].second - arr[(i + 1) % N].second);
		v.push_back(len);
		if (i != N - 1) v.push_back(dir);
		else v.push_back(2);
	}
	map<vector<int>, int> m;
	for (int i = 2; i <= v.size() - 1; i += 2) {
		for (int j = 1; i + j <= v.size(); j += 2) {
			vector<int> sub_v (v.begin() + i, v.begin() + j + i);
			if (m.find(sub_v) == m.end()) {
				m[sub_v] = 1;
			}
			else m[sub_v]++;
		}
	}
	int min_dist[200];
	int t = 0;
	for (int i = 0; i < N; i++) {
		min_dist[i] = t;
		t += v[2 * i + 1];
	}
	t = v[2 * N - 1];
	for (int i = N - 1; i > 0; i--) {
		min_dist[i] = min(min_dist[i], t);
		t += v[2 * (i - 1) + 1];
	}
	int ans = 0;
	for (int i = 2; i <= v.size() - 2; i += 2) {
		int index;
		int dist = 0;
		for (int j = 1; i + j <= v.size(); j += 2) {
			vector<int> sub_v (v.begin() + i, v.begin() + i + j);
			index = j;
			if (m[sub_v] == 1) break; 
			dist += v[i + j];
		}
		ans = max(ans, min_dist[(i + index) / 2 % N] + dist - min_dist[i / 2]);
	}
	cout << ans << endl;
}
