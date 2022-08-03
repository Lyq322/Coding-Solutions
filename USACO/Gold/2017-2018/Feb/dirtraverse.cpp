#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int N;
int files[100000];
vector<vector<int>> adj;
string name[100000];
ll total = 0;

int find_files(int pos) {
	if (files[pos] != -1) return files[pos];
	files[pos] = 0;
	for (int i = 0; i < adj[pos].size(); i++) {
		files[pos] += find_files(adj[pos][i]);
	}
	return max(1, files[pos]);
}

void dfs(int pos, int sz) {
    stack<pair<int, int>> st;
    st.push({pos, sz});
    while (!st.empty()) {
        int p = st.top().first;
        int s = st.top().second;
        st.pop();
        if (adj[p].size() == 0) {
            total += s - 1;
        }
        else {
            for (int i = 0; i < adj[p].size(); i++) {
                st.push({adj[p][i], s + 1 + name[adj[p][i]].size()});
            }
        }
    }
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
		files[i] = -1;
	}
	string f;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> f;
		name[i] = f;
		cin >> a;
		for (int j = 0; j < a; j++) {
			cin >> b;
			b--;
			adj[i].push_back(b);
		}
	}
	find_files(0);
	dfs(0, 0);
	stack<pair<int, ll>> s;
	s.push({0, total});
	ll ans = total;
	cout << total << endl;
	while (!s.empty()) {
		int pos = s.top().first;
		ll t = s.top().second;
		ans = min(ans, t);
		s.pop();
		for (int i = 0; i < adj[pos].size(); i++) {
			if (files[adj[pos][i]] == 0) continue;
			s.push({adj[pos][i], t + 3 * (files[0] - files[adj[pos][i]]) - (name[adj[pos][i]].size() + 1) * files[adj[pos][i]]});
		}
	}
	cout << ans << endl;
}
