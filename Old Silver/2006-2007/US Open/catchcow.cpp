#include <iostream>
#include <queue>

using namespace std;

int N, K;
bool visited[200000] = {0};

int main() {
    cin >> N >> K;
    if (N >= K) {
        cout << N - K << endl;
    }
    else {
        queue<pair<int, int>> q;
        q.push({N, 0});
        int ans = -1;
        while (!q.empty()) {
            int pos = q.front().first;
            int steps = q.front().second;
            cout << "pos " << pos << " steps " << steps << endl;
            q.pop();
            if (visited[pos]) {
                continue;
            }
            visited[pos] = true;
            if (pos >= K) {
                if (ans == -1 || pos - K + steps < ans) {
                    ans = pos - K + steps;
                }
            }
            else if (pos < 0) {
                continue;
            }
            else {
                q.push({2 * pos, steps + 1});
                q.push({pos + 1, steps + 1});
                q.push({pos - 1, steps + 1});
            }
        }
        cout << ans << endl;
    }
}