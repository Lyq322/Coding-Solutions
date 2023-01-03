#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

// Found the error :D
// When setting new values in the segtree, you need to check if there is already an old value there, and only set it if the new value is smaller

struct segtree{
	ll size;
	vector<pii> mins;
	
	void init(ll n) {
		size = 1;
		while (size < n) size *= 2;
		for (ll i = 0; i < 2 * size; i++) {
			mins.push_back({1000000000000000000, -1});
		}
	}

	void set(ll i, pii v, ll x, ll lx, ll rx) {
		if (rx - lx == 1) {
			mins[x] = v;
			return;
		}
		ll m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, 2 * x + 2, m, rx);
		}
		mins[x] = min(mins[2 * x + 1], mins[2 * x + 2]);
	}

	void set(ll i, pii v) {
		set(i, v, 0, 0, size);
	}

	pii minimum(ll l, ll r, ll x, ll lx, ll rx) {
		if (lx >= r || rx <= l) return {1000000000000000000, -1};
		if (lx >= l && rx <= r) return mins[x];
		ll m = (lx + rx) / 2;
		pii m1 = minimum(l, r, 2 * x + 1, lx, m);
		pii m2 = minimum(l, r, 2 * x + 2, m, rx);
		return min(m1, m2);
	}

	pii minimum(ll l, ll r) {
		return minimum(l, r, 0, 0, size);
	}
};

int main() {
	ifstream fin("boards.in");
	ofstream fout("boards.out");
	ll N, M;
	fin >> N >> M;
	vector<pair<pii, pii>> points;
	ll a, b, c, d;
	vector<ll> y_coords;
	for (ll i = 0; i < M; i++) {
		fin >> a >> b >> c >> d;
		points.push_back({{a, b}, {1, i}});
		points.push_back({{c, d}, {0, i}});
		y_coords.push_back(b);
		y_coords.push_back(d);
	}
	sort(points.begin(), points.end());
	y_coords.push_back(0);
	y_coords.push_back(N);
	sort(y_coords.begin(), y_coords.end());
	map<ll, ll> y_cc;
	ll index = 0;
	for (ll i = 0; i < y_coords.size(); i++) {
		if (y_cc.find(y_coords[i]) == y_cc.end()) {
			y_cc[y_coords[i]] = index;
			index++;
		}
	}
	segtree st;
	st.init(200010);
	st.set(y_cc[0], {0, -1});
	ll store_dist[100005];
	for (ll i = 0; i < points.size(); i++) {
		pii cur = points[i].first;
		ll type = points[i].second.first;
		ll index2 = points[i].second.second;
		if (type == 1) {
			pii m = st.minimum(0, y_cc[cur.second] + 1);
			ll actual_dist = m.first;
			ll new_dist;
			if (m.second != -1) {
				pii endpoint = points[m.second].first;
				actual_dist += endpoint.first + endpoint.second;
				new_dist = abs(cur.first - endpoint.first) + abs(cur.second - endpoint.second);
			}
			else {
				new_dist = cur.first + cur.second;
			}
			ll total_dist = new_dist + actual_dist;
			store_dist[index2] = total_dist;
		}
		else {
			ll dist = store_dist[index2];
			if (st.minimum(y_cc[cur.second], y_cc[cur.second] + 1).first > dist - cur.first - cur.second) st.set(y_cc[cur.second], {dist - cur.first - cur.second, i});
		}
	}
	pii cur = {N, N};
	pii m = st.minimum(0, y_cc[cur.second] + 1);
	ll actual_dist = m.first;
	ll new_dist;
	if (m.second != -1) {
		pii endpoint = points[m.second].first;
		actual_dist += endpoint.first + endpoint.second;
		new_dist = abs(cur.first - endpoint.first) + abs(cur.second - endpoint.second);
	}
	else {
		new_dist = cur.first + cur.second;
	}
	ll total_dist = new_dist + actual_dist;
	fout << total_dist << endl;
}
