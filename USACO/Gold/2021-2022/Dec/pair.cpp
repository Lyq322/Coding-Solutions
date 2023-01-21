#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
Notice that we can split the cows into groups where all adjacent cows in the group are within K distance
If T = 1, then all cows in a group with even # of cows will be paired, and all but 1 cows in an odd group will be paired
	We can simply loop over the possible unpaired cow in every odd group to get the answer in O(N)
For T = 2, we can use dp
*/

vector<vector<pii>> cows;
vector<vector<int>> previous;
int N, M, K;

void find_previous() {
	for (int i = 0; i < cows.size(); i++) {
		previous.push_back({});
		set<int> s;
		map<int, int> m;
		for (int j = 0; j < cows[i].size(); j++) {
			s.insert(cows[i][j].first);
			m[cows[i][j].first] = j;
		}
		for (int j = 0; j < cows[i].size(); j++) {
			auto it = s.lower_bound(cows[i][j].first - K);
			if (it == s.begin()) {
				previous[i].push_back(-1);
			}
			else {
				previous[i].push_back(m[*prev(it)]);
			}
		}
	}
}

int main() {
	cin >> N >> M >> K;
	pii arr[100000];
	for (int i = 0; i < M; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + M);

	int index = 0;
	cows.push_back({});
	cows[0].push_back(arr[0]);
	for (int i = 1; i < M; i++) {
		if (arr[i].first - arr[i - 1].first > K) {
			index++;
			cows.push_back({});
			cows[index].push_back(arr[i]);
		}
		else {
			cows[index].push_back(arr[i]);
		}
	}
	if (N == 1) {
		int ans = 0;
		for (int i = 0; i < cows.size(); i++) {
			if (cows[i].size() % 2 == 0) continue;
			int minimum = 100001;
			for (int j = 0; j < cows[i].size(); j++) {
				if (j % 2 == 0) {
					minimum = min(minimum, cows[i][j].second);
				}
				else {
					if (cows[i][j + 1].first - cows[i][j - 1].first <= K) {
						minimum = min(minimum, cows[i][j].second);
					}
				}
			}
			ans += minimum;
		}
		cout << ans << endl;
	}
	else {
		find_previous();
		int ans = 0;
		/*for (int i = 0; i < previous.size(); i++) {
			for (int j = 0; j < previous[i].size(); j++) {
				cout << previous[i][j] << ' ';
			}
			cout << endl;
		}*/
		for (int k = 0; k < cows.size(); k++) {
			if (cows[k].size() == 1) {
				ans += cows[k][0].second;
				continue;
			}
			int dp[100000][9];
			dp[0][1] = -1;
			dp[0][5] = -1;
			dp[0][6] = -1;
			dp[0][7] = -1;
			dp[0][8] = -1;
			dp[0][2] = cows[k][0].second;
			dp[0][3] = cows[k][0].second;
			dp[0][4] = cows[k][0].second;
			for (int i = 1; i < cows[k].size(); i++) {
				//cout << "i " << i << endl;
				int j = previous[k][i];
				//cout << j << endl;
				if (j != -1) {
					if (i != cows[k].size() - 1 && cows[k][i + 1].first - cows[k][i - 1].first <= K) {
						if ((i - j - 1) % 2 == 0) {
							if (j != 0) dp[i][5] = max(max(dp[j - 1][2], dp[j - 1][3]), max(max(dp[j - 1][4], dp[j - 1][7]), dp[j - 1][8]));
							else dp[i][5] = -1;
							dp[i][6] = max(max(dp[j][1], dp[j][5]), dp[j][6]);
							if (dp[i][5] != -1) dp[i][5] += cows[k][i].second;
							if (dp[i][6] != -1) dp[i][6] += cows[k][i].second;
							dp[i][1] = -1;
						}
						else {
							dp[i][1] = max(max(dp[j][2], dp[j][3]), max(max(dp[j][4], dp[j][7]), dp[j][8]));
							if (dp[i][1] != -1) dp[i][1] += cows[k][i].second;
							dp[i][5] = -1;
							dp[i][6] = -1;
						}
					}
					else {
						dp[i][1] = -1;
						dp[i][5] = -1;
						dp[i][6] = -1;
					}
					if ((i - j - 1) % 2 == 0) {
						dp[i][2] = max(max(dp[j][2], dp[j][3]), max(max(dp[j][4], dp[j][7]), dp[j][8]));
						if (dp[i][2] != -1) dp[i][2] += cows[k][i].second;
						dp[i][3] = -1;
						dp[i][4] = -1;
					}
					else {
						dp[i][3] = max(max(dp[j - 1][2], dp[j - 1][3]), max(max(dp[j - 1][4], dp[j - 1][7]), dp[j - 1][8]));
						if (dp[i][3] != -1) dp[i][3] += cows[k][i].second;
						dp[i][4] = max(dp[j][1], max(dp[j][5], dp[j][6]));
						if (dp[i][4] != -1) dp[i][4] += cows[k][i].second;
						dp[i][2] = -1;
					}
				}
				else {
					//cout << "hi?" << endl;
					if (i != cows[k].size() - 1 && cows[k][i + 1].first - cows[k][i - 1].first <= K) {
						if (i % 2 == 0) {
							dp[i][1] = -1;
						}
						else {
							dp[i][1] = cows[k][i].second;
						}
						dp[i][5] = -1;
						dp[i][6] = -1;
					}
					else {
						dp[i][1] = -1;
						dp[i][5] = -1;
						dp[i][6] = -1;
					}
					if (i % 2 == 0) {
						dp[i][2] = cows[k][i].second;
					}
					else {
						dp[i][2] = -1;
					}
					dp[i][3] = -1;
					dp[i][4] = -1;
				}
				if (i != 1) dp[i][7] = max(max(dp[i - 2][2], dp[i - 2][3]), max(max(dp[i - 2][4], dp[i - 2][7]), dp[i - 2][8]));
				else dp[i][7] = 0;
				dp[i][8] = max(max(dp[i - 1][1], dp[i - 1][5]), dp[i - 1][6]);
			}
			int m = 0;
			for (int i = 1; i <= 8; i++) {
				m = max(m, dp[cows[k].size() - 1][i]);
			}
			ans += m;
			/*cout << "dp " << endl;
			for (int l = 1; l < 9; l++) {
				for (int i = 0; i < cows[k].size(); i++) {
					cout << dp[i][l] << ' ';
				}
				cout << endl;
			}
			cout << m << endl;*/
		}
		cout << ans << endl;
	}
}
