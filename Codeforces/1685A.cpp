#include <bits/stdc++.h>
using namespace std;

int T, N;

int main() {
	cin >> T;
	for (int z = 0; z < T; z++) {
		cin >> N;
		vector<int> v;
		int a;
		for (int i = 0; i < N; i++) {
			cin >> a;
			v.push_back(a);
		}
		if (N % 2 == 1) {
			cout << "NO" << endl;
			continue;
		}
		sort(v.begin(), v.end());
		int index = 0;
		int s = 0;
		bool c = false;
		for (int i = 1; i < N; i++) {
			if (v[index] == v[i]) {
				s++;
			}
			else {
				s++;
				if (s >= N / 2 && index != 0) {
					cout << "NO" << endl;
					c = true;
					break;
				}
				else if (s > N / 2 && index == 0) {
					cout << "NO" << endl;
					c = true;
					break;
				}
				s = 0;
				index = i;
			}
		}
		if (c) continue;
		if (s >= N / 2 && index != 0) {
			cout << "NO" << endl;
			continue;
		}
		else if (s > N / 2 && index == 0) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				cout << v[i / 2] << ' ';
			}
			else {
				cout << v[N / 2 + i / 2] << ' ';
			}
		}
		cout << endl;
	}
}

/*
Idea
	Odd N never work
	Cannot have many identical numbers
		Eg. 1111123 won’t work
	⇒ How many identical # is too much?
		Work with examples:
			Say we have 4 3’s (3333)
			We need at least 4 1’s (or anything < 3) to make the arrangement work
			We can also use ≥ 4 5’s (or anything > 3) to make the arrangement work
			What about using them together?
			Eg. We need at least 2 1’s AND 3 5’s to make the arrangement work
		Conclusion
			Need at least the same number of identical #’s smaller than the identical # OR at least the same number of identical #’s greater than the identical #
				Eg. for 4 3’s, we need at least 4 1’s OR 4 5’s
			OR we can have the sum of the amount of numbers not equal to the identical number greater than the amount of identical #’s
				Eg. for 4 3’s, we need at least 3 1’s AND 2 5’s
			Can be checked by using a loop through the input array
	Everything else works :)
	Ordering
	Going from left to right filling in only the odd elements using the sorted input array (every other element)
	Go back to the start and fill in only the even elements using the sorted input array (the empty elements left)
	Eg. 1 _ 2 _ 3 _ 4 _
	⇒   1 5 2 6 3 7 4 8
*/