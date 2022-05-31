#include <iostream>

using namespace std;

int T, N, K;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        if (K == 1) {
            cout << "YES\n";
            for (int j = 1; j <= N; j++) {
                cout << j << endl;
            }
        }
        else if (N % 2 == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < K; k++) {
                    if (j % 2 == 0) {
                        cout << j * K + 1 + 2 * k << ' ';
                    }
                    else {
                        cout << (j - 1) * K + 2 + 2 * k << ' ';
                    }
                }
                cout << endl;
            }
        }
    }
}