#include <iostream>

using namespace std;

int T, N;
int num[200000];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> num[j];
        }
        if (num[N - 2] > num[N - 1]) {
            cout << -1 << endl;
            continue;
        }
        if (num[N - 1] < 0) {;
            bool b = false;
            for (int j = 0; j < N - 2; j++) {
                if (num[j] > num[j + 1]) {
                    b = true;
                    break;
                }
            }
            if (b) {
                cout << -1 << endl;
            }
            else {
                cout << 0 << endl;
            }
        }
        else {
            cout << N - 2 << endl;
            for (int j = 0; j < N - 2; j++) {
                cout << j + 1 << ' ' << N - 1 << ' ' << N << endl;
            }
        }
    }
}