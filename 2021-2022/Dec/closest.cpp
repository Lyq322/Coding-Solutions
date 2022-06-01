#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll K, M, N;
vector<pair<ll, ll>> grass;
vector<ll> cows;
vector<pair<ll, ll>> values;

bool comp(pair<ll, ll> a, pair<ll, ll> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}

int main() {
	cin >> K >> M >> N;
	ll a, b;
	for (ll i = 0; i < K; i++) {
		cin >> a >> b;
		grass.push_back({a, b});
	}
	for (ll i = 0; i < M; i++) {
		cin >> a;
		cows.push_back(a);
	}
	sort(grass.begin(), grass.end());
	sort(cows.begin(), cows.end());
	ll two_cows[200001] = {0};
	for (ll i = 0; i < K; i++) {
		auto right = lower_bound(cows.begin(), cows.end(), grass[i].first);
		if (right != cows.end() && *right == grass[i].first) {
			continue;
		}
		else {
			two_cows[distance(cows.begin(), right)] += grass[i].second;
		}
	}
	values.push_back({two_cows[0], 1});
	values.push_back({two_cows[M], 1});
	ll i = 0;
	while (i < K) {
		auto right = lower_bound(cows.begin(), cows.end(), grass[i].first);
		if (right == cows.end() || right == cows.begin()) {
			i++;
			continue;
		}
		ll left = 0;
		ll j = i;
		while (j < K) {
			auto right2 = lower_bound(cows.begin(), cows.end(), grass[j].first);
			if (distance(cows.begin(), right) != distance(cows.begin(), right2)) {
				break;
			}
			j++;
		}
		ll firstP = i;
		ll secondP = i;
		ll maximum = 0;
		ll total = grass[i].second;
		while (firstP < j && secondP < j) {
			if (2 * (grass[secondP].first - grass[firstP].first) < *right - *prev(right)) {
				maximum = max(maximum, total);
				secondP++;
				total += grass[secondP].second;
			}
			else {
				total -= grass[firstP].second;
				firstP++;
			}
		}
		values.push_back({maximum, 1});
		values.push_back({two_cows[distance(cows.begin(), right)] - maximum, 2});
		i = j;
	}
	sort(values.begin(), values.end(), comp);
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += values[i].first;
	}
	cout << ans << endl;
}
