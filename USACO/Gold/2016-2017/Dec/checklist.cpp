#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int H, G;
vector<pii> cow_h;
vector<pii> cow_g;

int dist(pii a, pii b) {
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

int main() {
	cin >> H >> G;
	int a, b;
	for (int i = 0; i < H; i++) {
		cin >> a >> b;
		cow_h.push_back({a, b});
	}
	for (int i = 0; i < G; i++) {
		cin >> a >> b;
		cow_g.push_back({a, b});
	}
	int dp1[1001][1001];
	int dp2[1001][1001];
	for (int i = 0; i <= H; i++) {
		for (int j = 0; j <= G; j++) {
			dp1[i][j] = -1;
			dp2[i][j] = -1;
		}
	}
	dp1[1][0] = 0;
	for (int i = 1; i <= H; i++) {
		for (int j = 0; j <= G; j++) {
			if (i > 1 && dp1[i - 1][j] != -1) {
				if (dp1[i][j] == -1) dp1[i][j] = dp1[i - 1][j] + dist(cow_h[i - 2], cow_h[i - 1]);
				else dp1[i][j] = min(dp1[i][j], dp1[i - 1][j] + dist(cow_h[i - 2], cow_h[i - 1]));
			}
			if (j > 0 && dp2[i - 1][j] != -1) {
				if (dp1[i][j] == -1) dp1[i][j] = dp2[i - 1][j] + dist(cow_g[j - 1], cow_h[i - 1]);
				else dp1[i][j] = min(dp1[i][j], dp2[i - 1][j] + dist(cow_g[j - 1], cow_h[i - 1]));
			}
			if (j > 1 && dp2[i][j - 1] != -1) {
				if (dp2[i][j] == -1) dp2[i][j] = dp2[i][j - 1] + dist(cow_g[j - 2], cow_g[j - 1]);
				else dp2[i][j] = min(dp2[i][j], dp2[i][j - 1] + dist(cow_g[j - 2], cow_g[j - 1]));
			}
			if (j > 0 && dp1[i][j - 1] != -1) {
				if (dp2[i][j] == -1) dp2[i][j] = dp1[i][j - 1] + dist(cow_h[i - 1], cow_g[j - 1]);
				else dp2[i][j] = min(dp2[i][j], dp1[i][j - 1] + dist(cow_h[i - 1], cow_g[j - 1]));
			}
		}
	}
	cout << dp1[H][G] << endl;
	/*
	A dp array to store the distance when we have already passed Holsteins i and Guernseys j
		However, if we only have one array we don’t know if we are at H_i and G_j
	2 dp arrays, dp1[i][j] is defined as already passed G_j and is at H_i and dp2[i][j] is defined as already passed H_i and is at G_j
	Calculate dp
	*/
}
