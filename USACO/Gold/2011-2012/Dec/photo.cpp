#include <bits/stdc++.h>
using namespace std;

int N;
int arr[5][20000];
vector<map<int, int>> m;

bool comp(int a, int b) {
	int l = 0;
	int g = 0;
	for (int i = 0; i < 5; i++) {
		if (m[i][a] < m[i][b]) l++;
		else g++;
	}
	if (l > g) return true;
	else return false;
}

int main() {
	cin >> N;
	for (int i = 0; i < 5; i++) {
		m.push_back({});
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j]; 
			m[i][arr[i][j]] = j;
		} 
	}
	sort(arr[0], arr[0] + N, comp);
	for (int i = 0; i < N; i++) {
		cout << arr[0][i] << endl;
	}
}
/*
Notice that if the majority of the comparison of two numbers’ position in the 5 arrays is pos_a < pos_b, then in the original array the two numbers also have to be pos_a < pos_b. The same is true for pos_a > pos_b
Use custom comparator to sort
*/