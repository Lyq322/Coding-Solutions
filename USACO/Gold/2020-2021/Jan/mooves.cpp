#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

/*
First we can simulate the first round of mooves, keeping track of the positions a cow starting at index i in an array of sets and the changed cow position array
Using the changed array, we can create a directed graph with <= N cycles, where if a -> b then the next position of cow at index a will be index b
Notice that if the cycle length is <= M / K, then all cows in the cycle will have been to the same positions — the union of the sets of all cows in the cycle
If the cycle length is longer, then we can maintain a sliding window, and add the remainder at the end
*/

int main() {
	ll N, M, K;
	cin >> N >> M >> K;

	ll cycles = K / M;
	int r = K % M;

	int a, b;
	vector<set<int>> pos;
	vector<set<int>> pos2;
	int arr[100000];
	for (int i = 0; i < N; i++) {
		pos.push_back({});
		pos[i].insert(i);
		pos2.push_back({});
		pos2[i].insert(i);
		arr[i] = i;
	}

	pii swap[200000];
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		a--;
		b--;
		swap[i] = {a, b};
	}

	for (int i = 0; i < M; i++) {
		int temp = arr[swap[i].first];
		arr[swap[i].first] = arr[swap[i].second];
		arr[swap[i].second] = temp;
		pos[arr[swap[i].first]].insert(swap[i].first);
		pos[arr[swap[i].second]].insert(swap[i].second);
		if (i < r) {
			pos2[arr[swap[i].first]].insert(swap[i].first);
			pos2[arr[swap[i].second]].insert(swap[i].second);
		}
	}

	int graph[100000];
	for (int i = 0; i < N; i++) {
		graph[arr[i]] = i;
	}

	int cycle_len[100000];
	bool visited[100000] = {0};
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			int next = graph[i];
			int count = 1;
			while (!visited[next]) {
				visited[next] = true;
				count++;
				next = graph[next];
			}
			cycle_len[i] = count;
		}
	}

	for (int i = 0; i < N; i++) {
		visited[i] = false;
	}
	int ans[100000];
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		if (cycle_len[i] <= cycles) {
			int next = graph[i];
			set<int> s;
			vector<int> nodes;
			nodes.push_back(i);
			for (int j : pos[i]) {
				s.insert(j);
			}
			while (!visited[next]) {
				visited[next] = true;
				nodes.push_back(next);
				for (int j : pos[next]) {
					s.insert(j);
				}
				next = graph[next];
			}
			for (int j = 0; j < nodes.size(); j++) {
				ans[nodes[j]] = s.size();
			}
		}
		else {
			vector<int> nodes;
			int next = graph[i];
			nodes.push_back(i);
			while (!visited[next]) {
				visited[next] = true;
				nodes.push_back(next);
				next = graph[next];
			}
			set<int> s;
			int track[100000] = {0};
			for (int k = 0; k < cycles; k++) {
				for (int j : pos[nodes[k]]) {
					s.insert(j);
					track[j]++;
				}
			}
			for (int k : pos2[nodes[cycles]]) {
				track[k]++;
				s.insert(k);
			}
			ans[nodes[0]] = s.size();
			for (int k : pos2[nodes[cycles]]) {
				track[k]--;
				if (track[k] == 0) {
					s.erase(s.find(k));
				}
			}
			for (int j = 1; j < nodes.size(); j++) {
				// j to j + cycles - 1, inclusive
				if (cycles != 0) {
					for (int k : pos[nodes[j - 1]]) {
						track[k]--;
						if (track[k] == 0) {
							s.erase(s.find(k));
						}
					}
					for (int k : pos[nodes[(j + cycles - 1) % nodes.size()]]) {
						track[k]++;
						s.insert(k);
					}
				}
				for (int k : pos2[nodes[(j + cycles) % nodes.size()]]) {
					track[k]++;
					s.insert(k);
				}
				ans[nodes[j]] = s.size();
				for (int k : pos2[nodes[(j + cycles) % nodes.size()]]) {
					track[k]--;
					if (track[k] == 0) {
						s.erase(s.find(k));
					}
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
