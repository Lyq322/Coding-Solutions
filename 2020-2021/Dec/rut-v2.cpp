#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pair<pii, int>> north;
vector<pair<pii, int>> east;
bool visited_n[1000] = {0};
bool visited_e[1000] = {0};
int blame[1000] = {0};

bool comp1(pair<pii, int> a, pair<pii, int> b) {
	return a.first.first < b.first.first;
}

bool comp2(pair<pii, int> a, pair<pii, int> b) {
	return a.first.second < b.first.second;
}

int check(pii a, pii b) {
	if (b.first - a.first == a.second - b.second) {
		return 0;
	}
	else if (b.first - a.first > a.second - b.second) {
		return 2;
	}
	else {
		return 1;
	}
}

int solve(int pos, char dir) {
	//cout << pos + 1 << ' ' << dir << endl;
	bool stopped = false;
	if (dir == 'N') {
		visited_n[pos] = true;
		for (int i = 0; i < east.size(); i++) {
			if (!visited_e[i] && east[i].first.second >= north[pos].first.second && north[pos].first.first >= east[i].first.first) {
				int b = solve(i, 'E');
				//cout << b << endl;
				if (b == -1 || b > pos) {					int intersect = check(east[i].first, north[pos].first);
					//cout << "intersect " << intersect << endl;
					if (intersect == 0) {
						continue;
					}
					else if (intersect == 1) {
						stopped = true;
						blame[east[i].second] += blame[north[pos].second] + 1;
						//cout << east[i].second << " plus " << blame[north[pos].second] + 1 << endl;
						return i;
					}
					else {
						blame[north[pos].second] += blame[east[i].second] + 1;
						//cout << north[pos].second << " plus " << blame[east[i].second] + 1 << endl;
					}
				}
			}
		}
	}
	else {
		visited_e[pos] = true;
		for (int i = 0; i < north.size(); i++) {
			if (!visited_n[i] && east[pos].first.second >= north[i].first.second && north[i].first.first >= east[pos].first.first) {
				int b = solve(i, 'N');
				if (b == -1 || b > pos) {
					int intersect = check(east[pos].first, north[i].first);
					if (intersect == 0) {
						continue;
					}
					else if (intersect == 1) {
						blame[east[pos].second] += blame[north[i].second] + 1;
						//cout << east[pos].second << " plus " << blame[north[i].second] + 1 << endl;
					}
					else {
						stopped = true;
						blame[north[i].second] += blame[east[pos].second] + 1;
						//cout << north[i].second << " plus " << blame[east[pos].second] + 1 << endl;
						return i;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	char d;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> d >> a >> b;
		if (d == 'E') {
			east.push_back({{a, b}, i});
		}
		else {
			north.push_back({{a, b}, i});
		}
	}
	sort(north.begin(), north.end(), comp1);
	sort(east.begin(), east.end(), comp2);
	for (int i = 0; i < north.size(); i++) {
		if (!visited_n[i]) {
			solve(i, 'N');
		}
	}
	for (int i = 0; i < east.size(); i++) {
		if (!visited_e[i]) {
			solve(i, 'E');
		}
	}
	for (int i = 0; i < N; i++) {
		cout << blame[i] << endl;
	}
}
