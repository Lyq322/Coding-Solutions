#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<pair<int, int>> v;
	v.push_back({1, 3});
	map<int, int> one2two = {{3, 2}, {1, 1}, {2, 3}};
	map<int, int> two2three = {{1, 2}, {3, 3}, {2, 1}};
	for (int i = 0; i < N - 1; i++) {
		vector<pair<int, int>> new_v;
		for (int j = 0; j < v.size(); j++) {
			new_v.push_back({one2two[v[j].first], one2two[v[j].second]});
		}
		new_v.push_back({1, 3});
		for (int j = 0; j < v.size(); j++) {
			new_v.push_back({two2three[v[j].first], two2three[v[j].second]});
		}
		v = new_v;
	}
	cout << v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].first << ' ' << v[i].second << endl;
	}
}
