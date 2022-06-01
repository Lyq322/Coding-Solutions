#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N;
vector<pair<pii, ll>> cities;
map<ll, ll> height;

bool comp(pair<pii, ll> a, pair<pii, ll> b) {
	if (a.first.first == b.first.first) {
		return a.second > b.second;
	}
	return a.first.first < b.first.first;
}

int main() {
	cin >> N;
	ll a, b, c;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b >> c;
		cities.push_back({{a, c}, 1});
		cities.push_back({{b, c}, -1});
	}
	sort(cities.begin(), cities.end(), comp);
	ll previous = cities[0].first.first;
	ll highest = cities[0].first.second;
	long long area = 0;
	height[cities[0].first.second] = 1;
	for (ll i = 1; i < 2 * N; i++) {
		area += highest * (cities[i].first.first - previous);
		if (cities[i].second == 1) {
			if (height.find(cities[i].first.second) != height.end()) height[cities[i].first.second]++;
			else height[cities[i].first.second] = 1;
		}
		else {
			height[cities[i].first.second]--;
			if (height[cities[i].first.second] == 0) height.erase(cities[i].first.second);
		}
		previous = cities[i].first.first;
		if (!height.empty()) highest = prev(height.end()) -> first;
		else highest = 0;
	}
	cout << area << endl;
}

// Interval question