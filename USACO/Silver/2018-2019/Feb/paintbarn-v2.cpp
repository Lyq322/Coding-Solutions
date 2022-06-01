#include <iostream>

using namespace std;

int N, K;
int grid[1010][1010];

int main() {
    cin >> N >> K;
    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        a++;
        b++;
        c++;
        d++;
        grid[a][b] += 1;
        grid[a][d] -= 1;
        grid[c][b] -= 1;
        grid[c][d] += 1;
    }
    for (int i = 1; i < 1010; i++) {
        for (int j = 1; j < 1010; j++) {
            grid[i][j] = grid[i][j] + grid[i][j - 1] + grid[i - 1][j] - grid[i - 1][j - 1];
        }
    }
    int ans;
    for (int i = 0; i < 1010; i++) {
        for (int j = 0; j < 1010; j++) {
            if (grid[i][j] == K) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}