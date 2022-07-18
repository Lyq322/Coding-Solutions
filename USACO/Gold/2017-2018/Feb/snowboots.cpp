#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, B;
pii snow[100000];
pair<pii, int> boots[100000];
bool ans[100000];
vector<int> v1;
vector<int> v2;

bool comp(pair<pii, int> a, pair<pii, int> b) {
	if (a.first.first == b.first.first) {
		return a.second < b.second;
	}
	return a.first.first < b.first.first;
}

int main() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> snow[i].first;
		snow[i].second = i;
	}
	for (int j = 0; j < B; j++) {
		cin >> boots[j].first.first >> boots[j].first.second;
		boots[j].second = j;
	}
	sort(snow, snow + N);
	sort(boots, boots + B, comp);
	multiset<int> m;
	set<int> s;
	int i = 0;
	while (i < N) {
		auto it2 = s.lower_bound(snow[i].second);
		if (s.size() == 0) {
			s.insert(snow[i].second);
		}
		else if (it2 == s.end()) {
			m.insert(snow[i].second - *prev(it2));
			s.insert(snow[i].second);
		}
		else if (it2 == s.begin()) {
			m.insert(*it2 - snow[i].second);
			s.insert(snow[i].second);
		}
		else {
			m.erase(m.find(*it2 - *prev(it2)));
			m.insert(*it2 - snow[i].second);
			m.insert(snow[i].second - *prev(it2));
			s.insert(snow[i].second);
		}
		for (int j = i + 1; j < N; j++) {
			if (snow[j].first != snow[i].first) break;
			auto it = s.lower_bound(snow[j].second);
			if (s.size() == 0) {
				s.insert(snow[j].second);
			}
			else if (it == s.end()) {
				m.insert(snow[j].second - *prev(it));
				s.insert(snow[j].second);
			}
			else if (it == s.begin()) {
				m.insert(*it - snow[j].second);
				s.insert(snow[j].second);
			}
			else {
				m.erase(m.find(*it - *prev(it)));
				m.insert(*it - snow[j].second);
				m.insert(snow[j].second - *prev(it));
				s.insert(snow[j].second);
			}
			i++;
		}
		v1.push_back(snow[i].first);
		v2.push_back(*prev(m.end()));
		i++;
	}
	for (int i = 0; i < B; i++) {
		int index = upper_bound(v1.begin(), v1.end(), boots[i].first.first) - v1.begin();
		if (index == 0) ans[boots[i].second] = 0;
		else {
			if (v2[index - 1] <= boots[i].first.second) ans[boots[i].second] = 1;
			else ans[boots[i].second] = 0;
		}
	}
	for (int i = 0; i < B; i++) {
		cout << ans[i] << endl;
	}
}

/*
We can first sort all boots and snow by their depths, while also keeping their original index using an array of pairs
We will “add in” each snow by their depths (eg the first time looping we will add all snow with depth = 1, second time 2, except that the array will be sorted so O(N) instead of O(???))
After we add in all snow with depth x, find the maximum interval that needs to be stepped over and compare that to the boots
	Standard (?) set question
	Multiset to store intervals
	Set to store current added snow
	To add more snow
		Use lowerbound to find the two neighboring snow in the set by their position
		Find the step needed from left neighbor to current and current to right neighbor
		Delete the step from left neighbor to right neighbor and insert the above two values into multiset
*/