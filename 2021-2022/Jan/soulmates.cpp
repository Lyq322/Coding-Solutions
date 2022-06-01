#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll N;

void solve(ll a, ll b) {
	vector<ll> reach;
	vector<ll> steps;
	reach.push_back(b);
	steps.push_back(0);
	ll k = b;
	ll count = 0;
	while (k != 1) {
		if (k % 2 == 0) {
			reach.push_back(k / 2);
			steps.push_back(count + 1);
			k = k / 2;
			count += 1;
		}
		else {
			reach.push_back((k - 1) / 2) ;
			steps.push_back(count + 2);
			k = (k - 1) / 2;
			count += 2;
		}
	}
	/*for (ll i = 0; i < reach.size(); i++) {
		cout << reach[i] << ' ' << steps[i] << endl;
	}*/
	reverse(reach.begin(), reach.end());
	reverse(steps.begin(), steps.end());
	ll ans = 0;
	ll cur = a;
	while (cur > b) {
		if (cur % 2 == 0) {
			cur = cur / 2;
			ans++;
		}
		else {
			cur = (cur + 1) / 2;
			ans += 2;
		}
	}
	if (cur == b) {
		cout << ans << endl;
		return;
	}
	bool found = false;;
	while (!found) {
		for (ll i = 0; i < reach.size() - 1; i++) {
			if (reach[i] <= cur && cur <= reach[i + 1]) {
				//cout << "current " << cur << ' ' << ans << endl;
				//cout << "between " << reach[i] << ' ' << reach[i + 1] << endl;
				//cout << "steps   " << steps[i] << ' ' << steps[i + 1] << endl;
				ll lower = steps[i];
				ll higher = steps[i + 1];
				ll temp = cur;
				if (cur % 2 == 0) {
					lower++;
					temp = cur / 2;
				}
				else {
					lower += 2;
					temp = (cur + 1) / 2;
				}
				lower += reach[i] - temp;
				higher += reach[i + 1] - cur;
				//cout << lower << ' ' << higher << endl;
				if (lower < higher) {
					if (cur % 2 == 0) {
						ans++;
					}
					else {
						ans += 2;
					}
					cur = temp;
				}
				else {
					ans += higher;
					found = true;
					break;
				}
			}
		}
	}
	cout << ans << endl;
}

int main() {
	cin >> N;
	ll a, b;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b;
		solve(a, b);
	}
}
