#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[100000];

bool check(int m) {
	int t = 0;
	int months = 1;
	for (int i = 0; i < N; i++) {
		if (arr[i] > m) return false;
		if (t + arr[i] > m) {
			months++;
			t = arr[i];
		}
		else {
			t += arr[i];
		}
	}
	return months <= M;
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}	
	int l = 0;
	int r = 1000000000;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == 0 || !check(m - 1))) {
			cout << m << endl;
			break;	
		}
		else if (check(m)) {
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
}

// Standard binary search question with bin search on answer