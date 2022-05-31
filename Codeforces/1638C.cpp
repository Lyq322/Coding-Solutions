#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int T, N;
int num[100000];

int main() {
    cin >> T;
    for (int j = 0; j < T; j++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> num[i];
        }
        stack<pair<int, int>> s;
        for (int i = 0; i < N; i++) {
            s.push({num[i], num[i]});
            while (s.size() >= 2) {
                pair<int, int> a = s.top();
                s.pop();
                pair<int, int> b = s.top();
                s.pop();
                if (b.second > a.first) {
                    s.push({min(a.first, b.first), max(a.second, b.second)});
                }
                else {
                    s.push(b);
                    s.push(a);
                    break;
                }
            }
        }
        cout << s.size() << endl;
    } 
}