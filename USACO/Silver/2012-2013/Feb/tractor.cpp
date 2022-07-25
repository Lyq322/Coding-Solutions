#include <bits/stdc++.h>
using namespace std;

int N;
int arr[500][500];
int di[4] = {0, 1, -1, 0};
int dj[4] = {1, 0, 0, -1};

bool check(int cost) {
    bool visited[500][500] = {{0}};
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (!visited[i][j]) {
                visited[i][j] = true;
                queue<pair<int, int>> q;
                q.push({i, j});
                int t = 1;
                while (!q.empty()) {
                    pair<int, int> pos = q.front();
                    q.pop();
                    for (int k = 0; k < 4; k++) {
                        int a = di[k] + pos.first;
                        int b = dj[k] + pos.second;
                        if (a >= 0 && b >= 0 && a < N && b < N && !visited[a][b] && abs(arr[a][b] - arr[pos.first][pos.second]) <= cost) {
                            visited[a][b] = true;
                            q.push({a, b});
                            t++;
                        }
                    }
                }
                if (t >= (N * N + 1) / 2) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    int l = 0;
    int r = 1000000;
    int m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (check(m) && (m == 0 || !check(m - 1))) {
            cout << m << endl;
            break;
        }
        else if (check(m)) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
}

/*
1. Binary search on answer
2. DSU
Need to precompute edges
*/