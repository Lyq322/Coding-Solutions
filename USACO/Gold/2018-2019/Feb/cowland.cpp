#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
Maintain 1 segment tree for finding the lca
Another one with range update for XOR
	Similar to range update for sums, but this time the prefix sum is for XOR
	Eg if the original array is a, b, c
	then the prefix sum will be a, a^b, b^c (since for any number x, x^x = 0)
	To update we can find the start and finish using the subtree size and do (^ old ^ new) to both
*/

struct Node {
	ll index;
	ll depth;
	ll value;
};

struct segtree1 {
	ll size;
	vector<Node> mins;
	
	void init(ll n) {
		size = 1;
		while (size < n) size *= 2;
		for (ll i = 0; i < 2 * size; i++) {
			mins.push_back({0, 0, 0});
		}
	}

	void build(vector<Node> &a, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				mins[x] = a[lx];
			}
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		if (mins[2 * x + 1].depth < mins[2 * x + 2].depth) mins[x] = mins[2 * x + 1];
		else mins[x] = mins[2 * x + 2];
	}

	void build(vector<Node> &a) {
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			mins[x].value = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		if (mins[2 * x + 1].depth < mins[2 * x + 2].depth) mins[x] = mins[2 * x + 1];
		else mins[x] = mins[2 * x + 2];
	}

	void set(ll i, ll v) {
		set(i, v, 0, 0, size);
	}

	Node minimum(ll l, ll r, ll x, ll lx, ll rx) {
		if (lx >= r || rx <= l) return {0, 1000000001, 0};
		else if (lx >= l && rx <= r) return mins[x];
		ll m = (lx + rx) / 2;
		Node m1 = minimum(l, r, 2 * x + 1, lx, m);
		Node m2 = minimum(l, r, 2 * x + 2, m, rx);
		if (m1.depth < m2.depth) {
			return m1;
		}
		else {
			return m2;
		}
	}

	Node minimum(ll l, ll r) {
		return minimum(l, r, 0, 0, size);
	}
};

struct segtree2 {
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
		sums[x] = sums[2 * x + 1] ^ sums[2 * x + 2];
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
		sums[x] = sums[2 * x + 1] ^ sums[2 * x + 2];
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
		return s1 ^ s2;
	}

	ll sum(ll l, ll r) {
		return sum(l, r, 0, 0, size);
	}
};

ll arr[100000];
vector<vector<ll>> adj;
vector<Node> tree;
vector<ll> values;
vector<ll> nodes;
vector<ll> subtree;

ll dfs(ll pos, ll depth, ll par, ll dist) {
	tree.push_back({pos, depth, dist});
	values.push_back(dist);
	nodes.push_back(pos);
	subtree.push_back(1);
	ll j = subtree.size() - 1;
	for (ll i = 0; i < adj[pos].size(); i++) {
		ll next = adj[pos][i];
		if (next != par) {
			subtree[j] += dfs(next, depth + 1, pos, dist ^ arr[next]);
			tree.push_back({pos, depth, dist});
		}
	}
	return subtree[j];
}

int main() {
	ifstream fin("cowland.in");
	ofstream fout("cowland.out");
	ll N, M;
	fin >> N >> M;
	for (ll i = 0; i < N; i++) {
		fin >> arr[i];
		adj.push_back({});
	}
	ll a, b;
	for (ll i = 0; i < N - 1; i++) {
		fin >> a >> b;
		a--;
		b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 1, -1, arr[0]);
	segtree1 st;
	st.init(2 * N - 1);
	st.build(tree);
	vector<ll> diff;
	diff.push_back(values[0]);
	for (ll i = 0; i < N - 1; i++) {
		diff.push_back(values[i + 1] ^ values[i]);
	}
	segtree2 st2;
	st2.init(N);
	st2.build(diff);
	ll c;
	ll indices[100000];
	for (ll i = 0; i < N; i++) {
		indices[nodes[i]] = i;
	}
	ll indices2[100000];
	for (ll i = 0; i < 2 * N - 1; i++) {
		indices2[tree[i].index] = i;
	}
	for (ll i = 0; i < M; i++) {
		fin >> a >> b >> c;
		if (a == 2) {
			b--;
			c--;
			ll lca = st.minimum(min(indices2[b], indices2[c]), max(indices2[b], indices2[c]) + 1).index;
			ll depth_a = st2.sum(0, indices[b] + 1);
			ll depth_b = st2.sum(0, indices[c] + 1);
			fout << (depth_a ^ depth_b ^ arr[lca]) << endl;
		}
		if (a == 1) {
			b--;
			st2.set(indices[b], st2.sum(indices[b], indices[b] + 1) ^ arr[b] ^ c);
			st2.set(indices[b] + subtree[indices[b]], st2.sum(indices[b] + subtree[indices[b]], indices[b] + subtree[indices[b]] + 1) ^ arr[b] ^ c);
			arr[b] = c;
		}
	}
}
