#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

bool comp(pii a, pii b) {
	if (a.first == b.first) return a.second > b.second;
	return a.first < b.first;
}

pii merge(pii a, pii b) {
	if (a.first > b.first) {
		swap(a, b);
	}
	if (b.second > a.second) {
		if (b.first - a.first <= b.second - a.second) {
			return b;
		}
		else {
			return {(a.first - a.second + b.first + b.second) / 2, (-a.first + a.second + b.first + b.second) / 2};
		}
	}
	else {
		if (b.first - a.first <= a.second - b.second) {
			return a;
		}
		else {
			return {(a.first - a.second + b.first + b.second) / 2, (-a.first + a.second + b.first + b.second) / 2};
		}
	}
}

int main() {
	ll T;
	cin >> T;
	for (ll z = 0; z < T; z++) {
		ll N, M;
		cin >> N >> M;
		pii rain[200000];
		vector<pii> v;
		for (ll i = 0; i < N; i++) {
			cin >> rain[i].first >> rain[i].second;
			v.push_back({rain[i].first - rain[i].second, 1});
			v.push_back({rain[i].first, -2});
			v.push_back({rain[i].first + rain[i].second, 1});
		}
		sort(v.begin(), v.end(), comp);
		ll cur_rain = 0;
		ll cur_slope = 0;
		vector<pii> flood;
		for (ll i = 0; i < v.size(); i++) {
			if (i != 0) cur_rain += cur_slope * (v[i].first - v[i - 1].first);
			cur_slope += v[i].second;
			if (v[i].second == -2 && cur_rain > M) {
				flood.push_back({v[i].first, cur_rain});
			}
		}
		if (flood.size() == 0) {
			for (ll i = 0; i < N; i++) {
				cout << 1;
			}
			cout << endl;
			continue;
		}
		pii merged = {flood[0].first * 2, flood[0].second * 2};
		for (ll i = 1; i < flood.size(); i++) {
			merged = merge(merged, {flood[i].first * 2, flood[i].second * 2});
		}
		for (ll i = 0; i < N; i++) {
			if (2 * rain[i].second - abs(2 * rain[i].first - merged.first) >= merged.second - 2 * M) {
				cout << 1;
			}
			else {
				cout << 0;
			}
		}
		cout << endl;
	}
}
