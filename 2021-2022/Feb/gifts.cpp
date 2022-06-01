#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int N;
int cows[500][500];
bool visited[500] = {0};
int ans[500] = {0};
vector<vector<int>> adj;
vector<set<int>> reach;
int start;

void dfs(int pos) {
    for (int i = 0; i < adj[pos].size(); i++) {
        int next = adj[pos][i];
        if (!visited[next]) {
            visited[next] = true;
            reach[start].insert(next);
            dfs(next);
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        adj.push_back({});
        reach.push_back({});
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> cows[i][j];
            cows[i][j]--;
        }
        for (int j = 0; j < N; j++) {
            if (cows[i][j] == i) {
                break;
            }
            adj[i].push_back(cows[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        start = i;
        for (int j = 0; j < N; j++) {
            visited[j] = false;
        }
        reach[i].insert(i);
        visited[i] = true;
        dfs(i);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (reach[i].find(cows[i][j]) != reach[i].end() && reach[cows[i][j]].find(i) != reach[cows[i][j]].end()) {
                ans[i] = cows[i][j];
                break;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] + 1 << endl;
    }
}