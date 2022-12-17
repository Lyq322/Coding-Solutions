#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

/*
Work backwards, opening up the farms and adding edges if necessary
Maintain a dsu to keep track of connected components
	Everytime a farm opens, cc++
	If united: cc--
*/

int par[200000];
int sz[200000];
int cc = 0;

struct dsu {
	vector<int> v;
	dsu(int n) { 
		v = vector<int>(n, -1); 
	}
	int get(int x) { 
		if (v[x] < 0) return x;
		else return v[x] = get(v[x]); 
	}
	bool connected(int a, int b) {
		return get(a) == get(b); 
	}
	int size(int x) { 
		return -v[get(x)]; 
	}
	bool unite(int x, int y) {
		x = get(x);
		y = get(y);
		if (x == y) return false;
		cc--;
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y]; 
		v[y] = x; 
		return true;
	}
};

bool comp(pair<pii, int> a, pair<pii, int> b) {
	return a.second < b.second;
}

int main() {
	ifstream fin("closing.in");
	ofstream fout("closing.out");
	int N, M;
	fin >> N >> M;
	pair<pii, int> edges[200000];
	int cows[200000];
	for (int i = 0; i < M; i++) {
		fin >> edges[i].first.first >> edges[i].first.second;
	}
	int index[200001];
	for (int i = 0; i < N; i++) {
		fin >> cows[N - i - 1];
		index[cows[N - i - 1]] = N - i - 1;
	}
	for (int i = 0; i < M; i++) {
		edges[i].second = max(index[edges[i].first.first], index[edges[i].first.second]);
	}
	sort(edges, edges + M, comp);
	dsu d(N + 1);
	int j = 0;
	bool ans[200000];
	for (int i = 0; i < N; i++) {
		cc++;
		while (j < M) {
			if (edges[j].second != i) break;
			d.unite(edges[j].first.first, edges[j].first.second);
			j++;
		}
		if (cc == 1) ans[N - i - 1] = true;
		else ans[N - i - 1] = false;
	}
	for (int i = 0; i < N; i++) {
		ans[i] ? fout << "YES" << endl : fout << "NO" << endl;
	}
}
