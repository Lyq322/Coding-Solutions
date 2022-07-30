#include <bits/stdc++.h>
using namespace std;

struct Rect {
	int x;
	int y;
	int l;
	int t;
};

bool comp(Rect a, Rect b) {
	return a.x < b.x;
}

int main() {
	int X, Y, I;
	cin >> X >> Y >> I;
	int a, b, c, d;
	vector<Rect> v; 
	for (int i = 0; i < I; i++) {
		cin >> a >> b >> c >> d;
		v.push_back({a, d + 1, b, 1});
		v.push_back({c + 1, d + 1, b, -1});
	}
	sort(v.begin(), v.end(), comp);
	multiset<pair<int, int>> sort_y;
	int ans = 0;
	int line;
	for (int i = 0 ; i < v.size(); i++) {
		if (i != 0) {
			ans += line * (v[i].x - v[i - 1].x);
		}
		if (v[i].t == 1) {
			sort_y.insert({v[i].y, -1});
			sort_y.insert({v[i].l, 1});
		}
		else {
			sort_y.erase(sort_y.find({v[i].y, -1}));
			sort_y.erase(sort_y.find({v[i].l, 1}));
		}
		int plow = 0;
		line = 0;
		for (auto it = sort_y.begin(); it != sort_y.end(); ++it) {
			if (plow > 0 && it != sort_y.begin()) {
				line += it -> first - prev(it) -> first;
			}
			plow += it -> second;
		}
	}
	cout << ans << endl;
}