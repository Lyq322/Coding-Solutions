#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll arr[200000];
vector<ll> values;
vector<ll> subtree;
vector<vector<ll>> adj;
vector<ll> tree;

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

ll dfs(ll pos, ll par, ll j) {
	ll count = 1;
	ll v = arr[pos];
	if (j >= 0) v += values[j];
	tree.push_back(pos);
	ll index = subtree.size();
	subtree.push_back(0);
	values.push_back(v);
	for (ll i = 0; i < adj[pos].size(); i++) {
		ll next = adj[pos][i];
		if (next != par) {
			count += dfs(next, pos, index);
		}
	}
	subtree[index] += count;
	return count;
}

int main() {
	ll N, M;
	cin >> N >> M;
	for (ll i = 0; i < N; i++) {
		cin >> arr[i];
		adj.push_back({});
	}
	ll a, b, c;
	for (ll i = 0; i < N - 1; i++) {
		cin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, -1, -1);
	vector<ll> diff;
	diff.push_back(values[0]);
	for (ll i = 0; i < N - 1; i++) {
		diff.push_back(values[i + 1] - values[i]);
	}
	segtree st;
	st.init(N);
	st.build(diff);
	ll index[200000];
	for (ll i = 0; i < N; i++) {
		index[tree[i]] = i;
	}
	for (ll i = 0; i < M; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			b--;
			ll difference = c - arr[b];
			arr[b] = c;
			st.set(index[b], difference + st.sum(index[b], index[b] + 1));
			if (index[b] + subtree[index[b]] < N) {
				st.set(index[b] + subtree[index[b]], st.sum(index[b] + subtree[index[b]], index[b] + subtree[index[b]] + 1) - difference);
			}
		}
		else {
			cin >> b;
			b--;
			cout << st.sum(0, index[b] + 1) << endl;
		}
	}
}
