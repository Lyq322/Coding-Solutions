#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> points;

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		points.push_back({a, b});
	}
	set<double> slopes;
	bool vertical = false;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int x_diff = points[i].first - points[j].first;
			int y_diff = points[i].second - points[j].second;
			if (x_diff == 0) {
				vertical = true;
			}
			else {
				slopes.insert((double) y_diff / x_diff);
			}
		}
	}
	if (vertical) cout << slopes.size() + 1 << endl;
	else cout << slopes.size() << endl;
}

/*
Solution 1 - Set of floats
	Implementation
		Set of floats called slopes, boolean called vertical
		Check each pair of points
		Push slope to slopes if slope is defined
		If not defined, set vertical = true
		Ans is the size of slopes + vertical
Solution 2 - Fractions
	Key Observation
		Floats may cause roundoff errors -> stay in fraction form instead
		Eg a / b ?= c / d ⇔ a*d ?= b*c
		***Negative denominators change the sign of the inequality***
		***Zero as a denominator***
*/