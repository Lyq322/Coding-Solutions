#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll n;
pii cows[100000];
map<ll, ll> polls;

void pmap(ll x, ll y) {
    if (polls.find(x) == polls.end()) {
        polls[x] = y;
    }
    else {
        polls[x] += y;
    }
}

int main() {
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        if (abs(cows[i].first - cows[i].second) <= abs(cows[i].first)) {
            continue;
        }
        if (cows[i].first * cows[i].second > 0) {
            pmap(2 * cows[i].first, -1);
            pmap(cows[i].second, 2);
            pmap(2 * cows[i].second - 2 * cows[i].first, -1);
        }
        else {
            pmap(0, -1);
            pmap(cows[i].second, 2);
            pmap(2 * cows[i].second, -1);
        }
    }
    ll total = 0;
    for (ll i = 0; i < n; i++) {
        total += abs(cows[i].first - cows[i].second);
    }
    ll ans = total;
    ll slope = 0;
    for (auto it = next(polls.begin()); it != polls.end(); it++) {
        ll d = it -> first - prev(it) -> first;
        slope += prev(it) -> second;
        total += slope * d;
        cout << "total " << total << endl;
        ans = min(ans, total);
    }
    cout << ans << endl;
}