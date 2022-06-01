#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int N;
vector<pii> dogs;
map<int, int> breeds;
set<int> distinct_breeds;

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		dogs.push_back({a, b});
		distinct_breeds.insert(b);
	}
	int t = distinct_breeds.size();
	sort(dogs.begin(), dogs.end());
	int i = 0;
	int j = 0;
	int ans = -1;
	while (i < N && j <= N) {
		if (breeds.size() == t) {
			if (ans == -1 || ans > dogs[j - 1].first - dogs[i].first) {
				ans = dogs[j - 1].first - dogs[i].first;
			}
			if (breeds[dogs[i].second] == 1) {
				breeds.erase(dogs[i].second);
			}
			else {
				breeds[dogs[i].second]--;
			}
			i++;
		}
		else {
			if (breeds.find(dogs[j].second) != breeds.end()) {
				breeds[dogs[j].second]++;
			}
			else {
				breeds[dogs[j].second] = 1;
			}
			j++;
		}
	}
	cout << ans << endl;
}
