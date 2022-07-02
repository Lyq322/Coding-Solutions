#include <bits/stdc++.h>
using namespace std;

int L, N, M;
int arr[50002];

bool check(int m) {
	int t = 0;
	int i = 0;
	int prev = -1;
	while (i < N + 1) {
		if (arr[i + 1] - arr[i] < m) {
			t++;
			if (arr[N + 1] - arr[i] < m) {
				t += N - prev;
				i = N + 1;
			}
			else {
				for (int j = i + 2; j <= N + 1; j++) {
					if (arr[j] - arr[i] >= m) {
						prev = i;
						i = j;
						break;
					}
					else {
						t++;
					}
				}
			}
		}
		else {
			prev = i;
			i++;
		}
		if (t > M) {
			return false;
		}
	}
	return true;
}

int main() {
	cin >> L >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	arr[N] = 0;
	arr[N + 1] = L;
	sort(arr, arr + N + 2);
	int l = 0;
	int r = L;
	int m;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (check(m) && (m == L || !check(m + 1))) {
			cout << m << endl;
			break;
		}
		else if (check(m)) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
}

// Binary search on answer