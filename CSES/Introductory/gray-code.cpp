#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<string> v;
	v.push_back("0");
	v.push_back("1");
	for (int i = 0; i < N - 1; i++) {
		vector<string> reverse;
		for (int j = v.size() - 1; j > -1; j--) {
			reverse.push_back(v[j]);
		}
		for (int j = 0; j < v.size(); j++) {
			v[j] = "0" + v[j];
		}
		for (int j = 0; j < reverse.size(); j++) {
			v.push_back("1" + reverse[j]);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
