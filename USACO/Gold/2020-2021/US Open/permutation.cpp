#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/*
Notice that the graph is just a bunch of different triangles
The points Bessie has currently already connected needs to be all inside a large triangle
For the next point to connect segments to, Bessie can either choose a point inside the large triangle that hasn’t been used yet, or a point outside the triangle that can connect to all three vertices of the triangle
Define a function f that takes in parameters of current large triangle (3 points) and an integer that stores the # of points that are not visited inside the large triangle
At each state, we can either choose to find a point outside or inside the current large triangle
	If it is outside, then we have to update the large triangle points and # of unvisited points inside accordingly
	If it is inside, then we have the same large triangle but the # of unvisited points decrease by 1
*/

pair<ll, bool> dp[40][40][40][40];
int points_inside[40][40][40] = {{{0}}};
int N;
ll mod = 1000000007;
pii points[40];

int ccw(pii a, pii b, pii c) {
	int area = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (area > 0) { // clockwise
		return 1;
	}
	else if (area < 0) { // counterclockwise
		return -1;
	}
	else return 0; // collinear
}

bool check(pii p1, pii p2, pii q1, pii q2) {
    int r1 = ccw(p1, p2, q1) * ccw(p1, p2, q2);
    int r2 = ccw(q1, q2, p1) * ccw(q1, q2, p2);
	return (r1 <= 0 && r2 <= 0);
}

bool in_triangle(int i, int j, int k, int l) {
	int count = 0;
	if (check(points[i], points[j], points[l], {points[l].first + 1, 100000})) {
		count++;
	}
	if (check(points[k], points[j], points[l], {points[l].first + 1, 100000})) {
		count++;
	}
	if (check(points[i], points[k], points[l], {points[l].first + 1, 100000})) {
		count++;
	}
	return (count % 2 == 1);
}

pair<ll, bool> solve(int a, int b, int c, int d) {
	if (dp[a][b][c][d].first != -1) return dp[a][b][c][d];
	if (dp[a][c][b][d].first != -1) return dp[a][c][b][d];
	if (dp[b][a][c][d].first != -1) return dp[b][a][c][d];
	if (dp[b][c][a][d].first != -1) return dp[b][c][a][d];
	if (dp[c][b][a][d].first != -1) return dp[c][b][a][d];
	if (dp[c][a][b][d].first != -1) return dp[c][a][b][d];
	dp[a][b][c][d].first = 0;
	if (d != 0) {
		if (solve(a, b, c, d - 1).second) {
			dp[a][b][c][d].first = (solve(a, b, c, d - 1).first * d) % mod;
			dp[a][b][c][d].second = true;
		}
	}
	int larger = 0;
	for (int i = 0; i < N; i++) {
		if (i != a && i != b && i != c) {
			if (!in_triangle(a, b, c, i)) {
				larger++;
				if (in_triangle(a, b, i, c)) {
					if (solve(a, b, i, d + points_inside[a][b][i] - points_inside[a][b][c] - 1).second) {
						dp[a][b][c][d].first = (dp[a][b][c][d].first + solve(a, b, i, d + points_inside[a][b][i] - points_inside[a][b][c] - 1).first) % mod;
						dp[a][b][c][d].second = true;
					}
				}
				else if (in_triangle(a, c, i, b)) {
					if (solve(a, c, i, d + points_inside[a][c][i] - points_inside[a][b][c] - 1).second) {
						dp[a][b][c][d].first = (dp[a][b][c][d].first + solve(a, c, i, d + points_inside[a][c][i] - points_inside[a][b][c] - 1).first) % mod;
						dp[a][b][c][d].second = true;
					}
				}
				else if (in_triangle(b, c, i, a)) {
					if (solve(c, b, i, d + points_inside[c][b][i] - points_inside[a][b][c] - 1).second) {
						dp[a][b][c][d].first = (dp[a][b][c][d].first + solve(c, b, i, d + points_inside[c][b][i] - points_inside[a][b][c] - 1).first) % mod;
						dp[a][b][c][d].second = true;
					}
				}
			}
		}
	}
	if (larger == 0) dp[a][b][c][d].second = true;
	dp[a][b][c][d].first = max(dp[a][b][c][d].first, (ll) 6);
	if (dp[a][b][c][d].second) {
		return dp[a][b][c][d];
	}
	else {
		dp[a][b][c][d].first = 0;
		return dp[a][b][c][d];
	}
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> points[i].first >> points[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < N; l++) {
					dp[i][j][k][l] = {-1, 0};
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				for (int l = 0; l < N; l++) {
					if (l != i && l != j && l != k) {
						if (in_triangle(i, j, k, l)) {
							points_inside[i][j][k]++;
							points_inside[i][k][j]++;
							points_inside[j][i][k]++;
							points_inside[j][k][i]++;
							points_inside[k][i][j]++;
							points_inside[k][j][i]++;
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				if (solve(i, j, k, points_inside[i][j][k]).second) ans = (ans + solve(i, j, k, points_inside[i][j][k]).first) % mod;
			}
		}
	}
	cout << ans << endl;
}
