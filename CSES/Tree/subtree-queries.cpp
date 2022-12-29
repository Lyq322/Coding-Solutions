#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree {
	ll size;
	vector<ll> sums;

	void init(ll n) {
		size = 1;
		while (size < n) size *= 2;
		sums.assign(2 * size, 0);
	}

	void build(vector<ll> &a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				sums[x] = a[lx];
			}
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void build(vector<ll> &a) {
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			sums[x] = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
	}

	void set(ll i, ll v) {
		set(i, v, 0, 0, size);
	}

	ll sum(ll l, ll r, ll x, ll lx, ll rx) {
		if (lx >= r || rx <= l) return 0;
		else if (lx >= l && rx <= r) return sums[x];
		ll m = (lx + rx) / 2;
		ll s1 = sum(l, r, 2 * x + 1, lx, m);
		ll s2 = sum(l, r, 2 * x + 2, m, rx);
		return s1 + s2;
	}

	ll sum(ll l, ll r) {
		return sum(l, r, 0, 0, size);
	}
};

vector<vector<ll>> adj;
ll dp[200000] = {0};

ll solve(ll pos, ll par) {
	if (dp[pos] != 0) return dp[pos];
	dp[pos] = 1;
	for (ll i = 0; i < adj[pos].size(); i++) {
		ll next = adj[pos][i];
		if (next != par) {
			dp[pos] += solve(next, pos);
		}
	}
	return dp[pos];
}

int main() {
	ll N, M;
	cin >> N >> M;
	ll arr[200000];
	ll a, b, c;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
	}
	for (ll i = 0; i < N; i++) {
		adj.push_back({});
	}
	for (ll i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	stack<ll> s;
	vector<ll> nodes;
	bool visited[200000] = {0};
	visited[0] = true;
	s.push(0);
	while (!s.empty()) {
		ll cur = s.top();
		s.pop();
		nodes.push_back(cur);
		for (ll i = 0; i < adj[cur].size(); i++) {
			ll next = adj[cur][i];
			if (!visited[next]) {
				visited[next] = true;
				s.push(next);
			}
		}
	}
	solve(0, -1);
	ll subtree[200000];
	for (ll i = 0; i < N; i++) {
		subtree[i] = dp[nodes[i]];
	}
	vector<ll> values;
	for (ll i = 0; i < N; i++) {
		values.push_back(arr[nodes[i]]);
	}
	segtree st;
	st.init(N);
	st.build(values);
	ll index[200000];
	for (ll i = 0; i < N; i++) {
		index[nodes[i]] = i;
	}
	for (ll i = 0; i < M; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			b--;
			st.set(index[b], c);
		}
		else {
			cin >> b;
			b--;
			cout << st.sum(index[b], index[b] + subtree[index[b]]) << endl;
		}
	}
}
