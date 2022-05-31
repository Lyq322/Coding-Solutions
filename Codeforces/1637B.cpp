#include <iostream>

using namespace std;

int T, N;
int num[100];

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> num[j];
        }
        int count = 0;
        int c1 = N;
        int c2 = N - 2;
        for (int j = 0; j < N; j++) {
            if (num[j] == 0) {
                count += c1;
            }
            c1 += c2;
            c2 -= 2;
        }
        for (int j = 0; j < N; j++) {
            count += (j + 1) * (N - j);
        }
        cout << count << endl;
    }
}