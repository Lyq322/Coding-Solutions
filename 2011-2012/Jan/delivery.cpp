#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> x_pos;
vector<int> y_pos;
pii places[100];
map<int, int> xm;
map<int, int> ym;
int grid[310][310] = {{0}};
int di[4] = {1, 0, -1, 0};
int dj[4] = {0, -1, 0, 1};
int xr[310] = {0};
int yr[310] = {0};
int x_index = 0;
int y_index = 0;

int bfs(int x, int y, int dest) {
	bool visited[310][310] = {{0}};
	queue<pair<pii, int>> q;
	visited[x][y] = true;
	q.push({{x, y}, 0});
	while (!q.empty()) {
		pii cur = q.front().first;
		int moves = q.front().second;
		q.pop();
		if (grid[cur.first][cur.second] == dest) return moves;
		for (int i = 0; i < 4; i++) {
			int a = cur.first + di[i];
			int b = cur.second + dj[i];
			if (a >= 0 && b >= 0 && a < x_index && b < y_index && !visited[a][b] && (grid[a][b] == 0 || grid[a][b] == dest)) {
				q.push({{a, b}, moves + abs(xr[a] - xr[cur.first]) + abs(yr[b] - yr[cur.second])});
				visited[a][b] = true;
			}
		}
	}
	return -1;
}

int main() {
	cin >> N;
	int a, b;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		x_pos.push_back(a);
		y_pos.push_back(b);
		for (int j = 0; j < 4; j++) {
			x_pos.push_back(a + di[j]);
			y_pos.push_back(b + dj[j]);
		}
		places[i] = {a, b};
	}
	sort(x_pos.begin(), x_pos.end());
	sort(y_pos.begin(), y_pos.end());
	for (int i = 0; i < x_pos.size(); i++) {
		if (xm.find(x_pos[i]) == xm.end()) {
			xm[x_pos[i]] = x_index;
			xr[x_index] = x_pos[i];
			x_index++;
		}
	} 
	for (int i = 0; i < y_pos.size(); i++) {
		if (ym.find(y_pos[i]) == ym.end()) {
			ym[y_pos[i]] = y_index;
			yr[y_index] = y_pos[i];
			y_index++;
		}
	}
	for (int i = 0; i < N; i++) {
		grid[xm[places[i].first]][ym[places[i].second]] = i + 1;
		places[i] = {xm[places[i].first], ym[places[i].second]};
	}
	int ans = 0;
	bool reached = true;
	int m;
	for (int i = 0; i < N; i++) {
		if (i != N - 1) m = bfs(places[i].first, places[i].second, i + 2);
		else m = bfs(places[i].first, places[i].second, 1);
		if (m == -1) {
			cout << -1 << endl;
			reached = false;
			break;
		}
		ans += m;
	}
	if (reached) cout << ans << endl;
}

/*
Solution 1 - Coordinate compression + BFS
	Key Observation
		Kind of tricky to implement, but can be coordinated compressed if original coordinates is stored in a reverse array (ie. arr[i] = j, where i is the compressed coord and j is the original)
		However, need to leave out space between each node
			Wrong example:
				Original
				. . . .
				. | . |
				. . . .
				Compressed
				| | . .
				. . . .
				. . . .
				No path between the two nodes
			Need to leave a space
			Solution - compress the four adj points surrounding a node
	Pseudocode
		Vector of x_coord and vector of y_coord that needs to be compressed called xr and yr
		Add all nodes from input and the four surround points to the above vectors
		Coord compress, keeping a reverse array to find the original coord
		For loop through all nodes
		Implement BFS on current node to the next node
		When pushing into queue, update moves using moves + abs(xr[a] - xr[cur.first]) + abs(yr[b] - yr[cur.second]) (adding the dist between the original coordinates)
Solution 2 - Dijkstra*
	Key Observation
		Data can be represented as a graph (similar to representing it as an adj vector instead of an adj matrix)
			⇒ need to find which nodes are connected, and which ones aren’t, and the distance/weight of each edge
		How do we know the route won’t turn more than once because of an obstacle
			⇒ make points surround the obstacle a node on the graph
		Which points?
			Where can the route go?
				We need the shortest path possible, so we should try to stick to the edge of the obstacle
		Conclusion: add 4 adj points of each node to the graph, edges only include paths with ≤ 1 turn
	N = 100, so N^3 is fine ⇒ can run dijkstra’s on every node
*/