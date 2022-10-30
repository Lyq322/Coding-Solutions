#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int arr[200000];
	for (int i = 0; i < N - 1; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N - 1);
	for (int i = 0; i < N - 1; i++) {
		if (arr[i] != i + 1) {
			cout << i + 1 << endl;
			break;
		}
	}
	if (arr[N - 2] == N - 1) {
		cout << N << endl;
	}
}
