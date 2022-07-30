#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N;
int paint[100001];
int start_c[100001];
int end_c[100001];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> paint[i];
		start_c[i] = -1;
		end_c[i] = -1;
	}
	start_c[N] = -1;
	for (int i = 0; i < N; i++) {
		if (start_c[paint[i]] == -1) start_c[paint[i]] = i;
		end_c[paint[i]] = i;
	}
	int layers = 0;
	vector<pii> canvas;
	for (int i = 1; i <= N; i++) {
		if (start_c[i] != -1) {
			canvas.push_back({start_c[i], -i});
			canvas.push_back({end_c[i], i});
		}
	}
	sort(canvas.begin(), canvas.end());
	stack<int> s;
	bool b = false;
	int ans = 0;
	for (int i = 0; i < canvas.size(); i++) {
		if (canvas[i].second > 0) {
			if (!s.empty() && s.top() == -canvas[i].second) {
				s.pop();
				layers--;
			}
			else {
				cout << -1 << endl;
				b = true;
				break;
			}
		}
		else {
			s.push(canvas[i].second);
			layers++;
		}
		ans = max(ans, layers);
	}
	if (!b) cout << ans << endl;
}

/*
Find the starting point and ending point of each color
We know that every color in between the starting and ending point of color x that is not x itself is going to be layer_of_x + 1
Interval problem
*/