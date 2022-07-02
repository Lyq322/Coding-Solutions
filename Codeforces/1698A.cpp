#include <bits/stdc++.h>
using namespace std;

int main() {
	int T, N, a;
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		int arr[100];
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < N; i++) {
			int a = 0;
			for (int j = 0; j < N; j++) {
				if (i != j) {
					a = a ^ arr[j];
				}
			}
			if (a == arr[i]) {
				cout << a << endl;
				break;
			}
		}
	}
}
