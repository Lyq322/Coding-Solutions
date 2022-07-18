#include <bits/stdc++.h>
using namespace std;

struct pii {
	int first;
	int second;
	int index;
};

vector<pii> bessie;
vector<pii> elsie;
vector<int> stop;
pii visited[200000] = {0};

bool comp1(pii a, pii b) {
	return a.second < b.second;
}

bool comp2(pii a, pii b) {
	return a.first < b.first;
}

bool comp(pii a, pii b) {
	return a.index < b.index;
}

int main() {
	int N, D;
	cin >> N >> D;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		bessie.push_back({a, b, i});
	}
	for (int i = 0; i < 2 * N; i++) {
		visited[i] = {0, 0, 0};
	}
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		elsie.push_back({a, b, i + N});
	}
	sort(bessie.begin(), bessie.end(), comp1);
	sort(elsie.begin(), elsie.end(), comp2);
	for (int i = 0; i < N; i++) {
		if (bessie[i].second == 0) {
			stop.push_back(i);
		}
		if (elsie[i].first == 0) {
			stop.push_back(i + N);
		}
		visited[i].index = bessie[i].index;
		visited[i + N].index = elsie[i].index;
	}
	queue<pii> q;
	for (int i = 0; i < stop.size(); i++) {
		if (stop[i] >= N) {
			q.push({stop[i], 1, 0});
			visited[stop[i]] = {1, 0, elsie[stop[i] - N].index};
		}
		else {
			q.push({stop[i], 1, 0});
			visited[stop[i]] = {1, 0, bessie[stop[i]].index};
		}
	}
	while (!q.empty()) {
		int pos = q.front().first;
		int dist = q.front().second;
		q.pop();
		pii pie;
		if (pos >= N) {
			pie = elsie[pos - N];
			pii temp = {0, pie.second - D, 0};
			int index = lower_bound(bessie.begin(), bessie.end(), temp, comp1) - bessie.begin();
			for (int i = index; i < N; i++) {
				if (bessie[i].second > pie.second) break;
				else if (visited[i].first == 0) {
					visited[i].first = dist + 1;
					q.push({i, dist + 1, 0});
				}
			}
		}
		else {
			pie = bessie[pos];
			pii temp = {pie.first - D, 0, 0};
			int index = lower_bound(elsie.begin(), elsie.end(), temp, comp2) - elsie.begin();
			for (int i = index; i < N; i++) {
				if (elsie[i].first > pie.first) break;
				else if (visited[i + N].first == 0) {
					visited[i + N].first = dist + 1;
					q.push({i + N, dist + 1, 0});
				}
			}
		}
	}
	sort(visited, visited + 2 * N, comp);
	for (int i = 0; i < N; i++) {
		if (visited[i].first != 0) cout << visited[i].first << endl;
		else cout << -1 << endl;
	}
}

/*
Shortest path question that can be solved using BFS since all paths weigh 1
We cannot calculate all possible paths before hand since that would be O(N^2)
	Use binary search (lower bound) on array to find next node on a sorted array
*/