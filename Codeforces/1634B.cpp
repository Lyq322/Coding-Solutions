#include <iostream>

using namespace std;

long long T, N, X, Y;
long long num[100000];

int main() {
    cin >> T;
    for (long long i = 0; i < T; i++) {
        cin >> N >> X >> Y;
        for (long long j = 0; j < N; j++) {
            cin >> num[j];
        }
        long long count = X % 2;
        for (long long j = 0; j < N; j++) {
            count += num[j] % 2;
        }
        if (count % 2 == Y % 2) {
            cout << "Alice" << endl;
        }
        else {
            cout << "Bob" << endl;
        }
    }
}