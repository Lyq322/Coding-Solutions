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
		if (v[x] > v[y]) swap(x, y);
		v[x] += v[y]; 
		v[y] = x; 
		return true;
	}
};
