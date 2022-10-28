#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define f first
#define s second

/*
Break up spring coordinates into starting coord and ending coord
Sort the coordinates by x coord -> y coord
At each start coord, we want to find the least number of steps to get to it, which is always from another spring’s end coord if there is one (that satisfies x and y coord is less than current coord)
	We can find the least moves by maintaining a minimum segment tree: st[y_value] = distance
	In order to compare only one number for distance, can use actual_dist - end_x - end_y as the distance we put in the segment tree
	This means we also need to store the current spring in the segment tree, so that when we find the minimum we can get the actual dist back by adding end_x and end_y
	Therefore at each start coord, we want to find the least distance using the segment tree (or no spring) and store it in an array to use it when the loop got to the end coord of the cur spring
At each end coord, we want to update the segtree with the value we stored when we cal it during the start coord
11/15 >:C, will fix later :’(
*/


pair<pii, pii> boards[100000];

struct segtree {
	int size;
	vector<pii> mins;

	void init(int N) {
		size = 1;
		while (size < N) size *= 2;
		mins.assign(2 * size, {2000000000, -1});
	}

	void set(int i, int v, int index, int x, int lx, int rx) {
		if (rx - lx == 1) {
			mins[x].f = v;
			mins[x].s = index;
			return;
		}
		int m = (lx + rx) / 2;
		if (i < m) {
			set(i, v, index, 2 * x + 1, lx, m);
		}
		else {
			set(i, v, index, 2 * x + 2, m, rx);
		}
		if (mins[2 * x + 1].f > mins[2 * x + 2].f) {
			mins[x] = mins[2 * x + 2];
		}
		else {
			mins[x] = mins[2 * x + 1];
		}
	}

	void set(int i, int v, int y) {
		set(i, v, y, 0, 0, size);
	}

	pii min(int l, int r, int x, int lx, int rx) {
		if (lx >= r || rx <= l) return {2000000000, -1};
		if (lx >= l && rx <= r) return mins[x];
		int m = (lx + rx) / 2;
		pii m1 = min(l, r, 2 * x + 1, lx, m);
		pii m2 = min(l, r, 2 * x + 2, m, rx);
		if (m1.f > m2.f) {
			return m2;
		}
		else {
			return m1;
		}
	}

	pii min(int l, int r) {
		return min(l, r, 0, 0, size);
	}
};

bool comp(pair<pii, pii> a, pair<pii, pii> b) {
	if (a.f.f == b.f.f) {
		if (a.f.s == b.f.s) {
			return a.s.f > b.s.f;
		}
		return a.f.s < b.f.s;
	}
	return a.f.f < b.f.f;
}

bool comp2(pair<pii, pii> a, pair<pii, pii> b) {
	return a.s.s < b.s.s;
}

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> boards[i].f.f >> boards[i].f.s >> boards[i].s.f >> boards[i].s.s;
	}
	segtree st;
	st.init(200010);
	map<int, int> m;
	int index = 0;
	vector<int> cc;
	for (int i = 0; i < M; i++) {
		cc.push_back(boards[i].s.s);
		cc.push_back(boards[i].f.s);
	}
	sort(cc.begin(), cc.end());
	m[0] = 0;
	for (int i = 0; i < cc.size(); i++) {
		if (i == 0 && cc[i] != 0) {
			index++;
			m[cc[i]] = index;
		}
		else if (cc[i] != cc[i - 1]) {
			index++;
			 m[cc[i]] = index;
		}
	}
	if (N != cc[cc.size() - 1]) {
		index++;
	}
	m[N] = index;
	vector<pair<pii, pii>> points;
	for (int i = 0; i < M; i++) {
		if (boards[i].f == boards[i].s) continue;
		points.push_back({boards[i].f, {0, i}});
		points.push_back({boards[i].s, {1, i}});
	}
	sort(points.begin(), points.end(), comp);
	int store_min[100000];
	for (int i = 0; i < points.size(); i++) {
		if (points[i].s.f == 0) {
			pii start = points[i].f;
			pii minimum = st.min(0, m[start.s] + 1);
			int actual;
			if (minimum.s == -1) {
				actual = start.f + start.s;
			}
			else {
				actual = minimum.f + boards[minimum.s].s.f + boards[minimum.s].s.s + start.f - boards[minimum.s].s.f + start.s - boards[minimum.s].s.s;
			}
			store_min[points[i].s.s] = actual;
		}
		else {
			pii end = points[i].f;
			int actual = store_min[points[i].s.s];
			st.set(m[end.s], actual - end.f - end.s, points[i].s.s);
		}

	}
	pii minimum = st.min(0, m[N] + 1);
	int actual = min(minimum.f + 2 * N, 2 * N);
	cout << actual << endl;
}
