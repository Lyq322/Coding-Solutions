#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, X, Y;
	cin >> N >> X >> Y;
	int a, b;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		v1.push_back(a);
		v2.push_back(b);
	}
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (v1[i] > v2[i]) {
			ans += Y * (v1[i] - v2[i]);
		}
		else if (v1[i] < v2[i]) {
			ans += X * (v2[i] - v1[i]);
		}
	}
	cout << ans << endl;
}
