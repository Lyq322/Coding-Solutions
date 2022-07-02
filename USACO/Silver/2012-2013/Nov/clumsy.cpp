#include <bits/stdc++.h>
using namespace std;

int main() {
	string s;
	getline(cin, s);
	int left = 0;
	int right = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s.at(i) == '(') left++;
		else right++;
	}
	int changes = 0;
	int l = 0;
	int r = 0;
	for (int i = 0; i < s.size(); i++) {
		if (l == s.size() / 2) {
			cout << changes + abs(left - l + changes) << endl;
			break;
		}
		if (s.at(i) == '(') {
			l++;
		}
		else r++;
		if (r > l) {
			changes++;
			r--;
			l++;
		}
	}
}

/*
Loop over string to find the # of left and right parentheses
Loop over string again, keeping variables l to keep track of ‘(‘, r to keep track of ‘)’, and changes to keep track of num of changes needed for l >= r (changes is essentially how many changes needed for ‘(‘ to ‘)’)
	Update change var as needed (l < r)
	The loop will end when we have reached l == string.size() / 2
		We can calculate the number of ‘)’ we need to change to ‘(‘ by using left - l + changes
			l - changes is the number of ‘(‘ that were originally there in the original string
			Left - (l - changes) is the number of ‘(‘ that are to the right of the current index
*/