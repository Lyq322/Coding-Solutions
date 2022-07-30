#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, M;
	cin >> N >> M;
	int a, b;
	set<int> s;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		while (!s.empty()) {
			if (*prev(s.end()) > b) {
				s.erase(prev(s.end()));
				ans++;
			}
			else break;
		}
		if (b != 0) s.insert(b);
	}
	ans += s.size();
	cout << ans << endl;
}
