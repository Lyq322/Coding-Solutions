#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	int people[200000];
	int room[200000];
	for (int i = 0; i < N; i++) {
		cin >> people[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> room[i];
	}
	sort(people, people + N);
	sort(room, room + M);
	int i = 0;
	int j = 0;
	int ans = 0;
	while (i < N && j < M) {
		if (abs(people[i] - room[j]) <= K) {
			i++;
			j++;
			ans++;
		}
		else {
			if (people[i] > room[j]) {
				j++;
			}
			else {
				i++;
			}
		}
	}
	cout << ans << endl;
}
