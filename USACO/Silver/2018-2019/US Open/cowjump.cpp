#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

ll N;
vector<pair<pii, pii>> points;
vector<pair<pii, pii>> cows;

bool comp(pair<pii, pii> a, pair<pii, pii> b) {
	if (a.first.first == b.first.first) {
		return a.second.first < b.second.first;
	}
	return a.first.first < b.first.first;
}

void print(pair<pii, pii> a) {
	cout << a.first.first << ' ' << a.first.second << ' ' << a.second.first << ' '<< a.second.second << endl;
}

bool on_line(pii a, pii b, pii c) {
	if (b.first <= max(a.first, c.first) && b.first >= min(a.first, c.first) && b.second <= max(a.second, c.second) && b.second >= min(a.second, c.second)) {
       return true;
	}
    return false;
}

ll orientation(pii a, pii b, pii c) {
    ll val = (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second);
    if (val == 0) {
		return 0;
	}
    else if (val > 0) {
		return 1;
	}
	else {
		return 2;
	}
}

bool check(pii p1, pii q1, pii p2, pii q2) {
    ll o1 = orientation(p1, q1, p2);
    ll o2 = orientation(p1, q1, q2);
    ll o3 = orientation(p2, q2, p1);
    ll o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4) {
        return true;
	}
    if (o1 == 0 && on_line(p1, p2, q1)) return true;
    if (o2 == 0 && on_line(p1, q2, q1)) return true;
    if (o3 == 0 && on_line(p2, p1, q2)) return true;
    if (o4 == 0 && on_line(p2, q1, q2)) return true;
    return false;
}

int main() {
	cin >> N;
	ll a, b, c, d;
	for (ll i = 0; i < N; i++) {
		cin >> a >> b >> c >> d;
		if (a < c) {
			points.push_back({{a, b}, {0, i}});
			points.push_back({{c, d}, {1, i}});
			cows.push_back({{a, b}, {c, d}});
		}
		else {
			points.push_back({{a, b}, {1, i}});
			points.push_back({{c, d}, {0, i}});
			cows.push_back({{c, d}, {a, b}});
		}
	}
	sort(points.begin(), points.end(), comp);
	set<pii> start_points;
	ll intersections[100000] = {0};
	for (ll i = 0; i < 2 * N; i++) {
		if (points[i].second.first == 0) {
			start_points.insert({points[i].first.second, points[i].second.second});
		}
		else {
			pii s = cows[points[i].second.second].first;
			auto right = start_points.lower_bound({s.second, points[i].second.second});
			if (next(right) == start_points.end()) {
				if (right == start_points.begin()) {
				}
				else if (check(cows[right -> second].first, cows[right -> second].second, cows[prev(right) -> second].first, cows[prev(right) -> second].second)) {
					print(cows[right -> second]);
					print(cows[prev(right) -> second]);
					cout << right -> second << ' ' << prev(right) -> second << endl;
					intersections[right -> second]++;
					intersections[prev(right) -> second]++;
				}
			}
			else if (right == start_points.begin()) {
				if (check(cows[right -> second].first, cows[right -> second].second, cows[next(right) -> second].first, cows[next(right) -> second].second)) {
					print(cows[right -> second]);
					print(cows[next(right) -> second]);
					cout << right -> second << ' ' << next(right) -> second << endl;
					intersections[right -> second]++;
					intersections[next(right) -> second]++;
				}
			}
			else {
				if (check(cows[right -> second].first, cows[right -> second].second, cows[next(right) -> second].first, cows[next(right) -> second].second)) {
					print(cows[right -> second]);
					print(cows[next(right) -> second]);
					cout << right -> second << ' ' << next(right) -> second << endl;
					intersections[right -> second]++;
					intersections[next(right) -> second]++;
				}
				if (check(cows[right -> second].first, cows[right -> second].second, cows[prev(right) -> second].first, cows[prev(right) -> second].second)) {
					print(cows[right -> second]);
					print(cows[prev(right) -> second]);
					cout << right -> second << ' ' << prev(right) -> second << endl;
					intersections[right -> second]++;
					intersections[prev(right) -> second]++;
				}
			}
			start_points.erase(right);
		}
	}
	bool e = false;
	for (ll i = 0; i < N; i++) {
		if (intersections[i] >= 1) cout << i << ' ' << intersections[i] << endl;
		if (intersections[i] > 1) {
		    cout << i + 1 << endl;
			e = true;
		    break;
		}
	}
	if (!e) {
		for (ll i = 0; i < N; i++) {
			if (intersections[i] == 1) {
				cout << i + 1 << endl;
				break;
			}
		}
	}
}
