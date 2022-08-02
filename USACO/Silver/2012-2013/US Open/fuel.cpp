#include <bits/stdc++.h>
#include <exception>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

int main() {
	ll N, G, B, D;
	cin >> N >> G >> B >> D;
	pii arr[50001];
	for (ll i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N);
	arr[N] = {D, 0};
	stack<ll> s;
	ll cheap[50001];
	for (ll i = 0; i <= N; i++) cheap[i] = -1;
	for (ll i = N; i > -1; i--) {
		while (!s.empty()) {
			if (arr[s.top()].second <= arr[i].second) {
				cheap[i] = s.top();
				break;
			}
			else s.pop();
		}
		s.push(i);
	}
	ll cost = 0;
	bool b = true;
	ll current_fuel = B - arr[0].first;
	for (ll i = 0; i < N; i++) {
		if (current_fuel < 0) {
			cout << -1 << endl;
			b = false;
			break;
		}
		if (cheap[i] == -1) {
			cost += (G - current_fuel) * arr[i].second;
			current_fuel = G;
		}
		else {
			if (arr[cheap[i]].first - arr[i].first > G) {
				cost += (G - current_fuel) * arr[i].second;
				current_fuel = G;	
			}
			else {
				cost += max((long long) 0, (arr[cheap[i]].first - arr[i].first) - current_fuel) * arr[i].second;
				current_fuel = max(current_fuel, arr[cheap[i]].first - arr[i].first);
			}
		}
		current_fuel -= arr[i + 1].first - arr[i].first;
	}
	if (b) cout << cost << endl;
}

/*
First observe that we want to go to a cheaper gas station rather than an expensive one
This means that if we are currently at gas station x, and there is a cheaper gas station y further down the road
If we have enough gas to go to y, then we skip x
If we don’t have enough gas to go to y, then we buy just enough fuel at x to go to y
However, notice that if distance between y - x is greater than G, then we will not have enough fuel to go to the next cheapest gas station
In this case, we just fill the entire tank at x since there are no cheap gas stations that are within G units of distance
*/