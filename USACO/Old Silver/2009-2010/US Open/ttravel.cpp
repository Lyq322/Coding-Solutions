#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main() {
	int N, K;
	cin >> N;
	char c;
	pii arr[80001];
	arr[0] = {-1, -1};
	for (int i = 1; i <= N; i++) {
		cin >> c;
		if (c == 'a') {
			cin >> K;
			arr[i].first = K;
			arr[i].second = i - 1;
		}
		else if (c == 's') {
			arr[i].first = arr[arr[i - 1].second].first;
			arr[i].second = arr[arr[i - 1].second].second;
		}
		else {
			cin >> K;
			arr[i].first = arr[K - 1].first;
			arr[i].second = arr[K - 1].second;
		}
		cout << arr[i].first << endl;
	}
}

/*
We only need the last added element after every move, so we can store each lasted element in an array
However, we also need to be able to backtrack to a previous arrangement
Solution is to store the index of the previous position, since the time skip will mess things up
*/