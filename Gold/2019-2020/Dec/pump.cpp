#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

struct City {
	int cost;
	int flow;
	int pos;
};

int N, M;
vector<vector<City>> adj;
int flows[1000];

bool operator<(City a, City b) {
	return a.cost > b.cost;
}

City cal(int min_flow) {
	priority_queue<City> q;
	q.push({0, 0, 0});
	int dist[1000] = {0};
	for (int i = 1; i < N; i++) {
		dist[i] = -1;
	}
	bool visited[1000] = {0};
	while (!q.empty()) {
		int cur = q.top().pos;
		int cur_cost = q.top().cost;
		q.pop();
		if (visited[cur]) continue;
		visited[cur] = true;
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i].pos;
			int next_cost = adj[cur][i].cost;
			int next_flow = adj[cur][i].flow;
			if (!visited[next] && (dist[next] == -1 || dist[next] > next_cost + cur_cost) && next_flow >= min_flow) {
				dist[next] = next_cost + cur_cost;
				q.push({dist[next], 0, next});
			}
		}
	}
	return {dist[N - 1], min_flow, 0};
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		adj.push_back({});
	}
	int a, b, c, f;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c >> f;
		a--;
		b--;
		adj[a].push_back({c, f, b});
		adj[b].push_back({c, f, a});
		flows[i] = f;
	}
	sort(flows, flows + M);
	City ans = {-1, -1, -1};
	for (auto i = 0; i < M; i++) {
		City t = cal(flows[i]);
		if (t.cost == -1) break;
		if (ans.flow == -1 ||  ans.flow * t.cost < t.flow * ans.cost) {
			ans = t;
		}
	}
	cout << floor((double) ans.flow / ans.cost * 1000000) << endl;
}
/*
**A dijkstra that only uses the flow/cost does not work since fractions don’t work the same as integers**
	If we know that a / b > c / d
	It does not mean (a + e)/(b + f) > (c + e)/(b + f)
Idea
	O(N^2) works since N is only 1000
	We know that dijkstra with only one weight/one variable works
	⇒ Let us set the minimum flow as a constant
	⇒ We cal the answer by looping through all possible minimum flows
	Run dijkstra in that loop, only using edges with greater flow than the cur minimum flow and finding the least cost possible
*/