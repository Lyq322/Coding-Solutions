#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mod = 2019201997;

struct Node {
	int weight;
	int pos;
};

bool operator<(Node a, Node b) {
	return a.weight > b.weight;
}

int main() {
	ifstream fin("walk.in");
	ofstream fout("walk.out");
	int N, K;
	fin >> N >> K;
	int mst[7500];
	for (int i = 1; i < N; i++) {
		mst[i] = -1;
	}
	mst[0] = 0;
	bool visited[7500] = {0};
	priority_queue<Node> q;
	q.push({0, 0});
	while (!q.empty()) {
		int cur = q.top().pos;
		int w = q.top().weight;
		q.pop();
		if (visited[cur]) {
			break;
		}
		visited[cur] = true;
		for (int i = 0; i < N; i++) {
			int dist = ((ll) 2019201913 * min(i + 1, cur + 1) + (ll) 2019201949 * max(i + 1, cur + 1)) % mod;
			if (!visited[i] && (mst[i] == -1 || dist < mst[i])) {
				mst[i] = dist;
				q.push({dist, i});
			}
		}
	}
	sort(mst, mst + N);
	fout << mst[N - K + 1] << endl;
}
