#include <bits/stdc++.h>
#include <pthread.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	set<int> s;
	int a;
	for (int i = 0; i < N; i++) {
		cin >> a;
		s.insert(a);
	}
	cout << s.size() << endl;
}
