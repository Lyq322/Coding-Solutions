#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Rect {
	ll x;
	ll y;
	ll l;
	ll t;
};

bool comp(Rect a, Rect b) {
	return a.x < b.x;
}

int main() {
	ll N;
	cin >> N;
	vector<Rect> v;
	ll a, b, c, d;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		v.push_back({a, b, d, 1});
		v.push_back({c, b, d, -1});
	}
	sort(v.begin(), v.end(), comp);
	multiset<pair<ll, ll>> s;
	ll ans = 0;
	ll previous;
	for (ll i = 0; i < v.size(); i++) {
		ll layers = 0;
		ll prev;
		ll t = 0;
		for (auto it = s.begin(); it != s.end(); it++) {
			if (layers > 0) {
				t += it -> first - prev;
			}
			if (it -> second == 1) {
				layers++;
			}
			else layers--;
			prev = it -> first;
		}
		if (i != 0) ans += t * (v[i].x - previous);
		if (v[i].t == 1) {
			s.insert({v[i].l, 1});
			s.insert({v[i].y, -1});
		}
		else {
			s.erase(s.find({v[i].l, 1}));
			s.erase(s.find({v[i].y, -1}));
		}
		previous = v[i].x;
	}
	cout << ans << endl;
}
