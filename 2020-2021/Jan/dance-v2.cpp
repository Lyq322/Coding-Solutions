#include <bits/stdc++.h>

using namespace std;

int N, K;
bool visited[100000] = {0};
int ans[100000] = {0};
vector<set<int>> s;
int cur[100000];

int main() {
	cin >> N >> K;
	int a, b;
	for (int i = 0; i < N; i++) {
		s.push_back({});
	}
	for (int i = 0; i < N; i++) {
		s[i].insert(i);
		cur[i] = i;
	}
	for (int i = 0; i < K; i++) {
		cin >> a >> b;
		int temp = cur[a - 1];
		cur[a - 1] = cur[b - 1];
		cur[b - 1] = temp;
		s[cur[a - 1]].insert(a - 1);
		s[cur[b - 1]].insert(b - 1);
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			int pos = i;
			set<int> p;
			vector<int> v;
			while (!visited[pos]) {
				visited[pos] = true;
				v.push_back(pos);
				for (auto it = s[pos].begin(); it != s[pos].end(); ++it) {
					p.insert(*it);
				}
				pos = cur[pos];
			}
			for (int j = 0; j < v.size(); j++) {
				ans[v[j]] = p.size();
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << ans[i] << endl;
	}
}
