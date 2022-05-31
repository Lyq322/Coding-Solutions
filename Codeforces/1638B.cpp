#include <iostream>

using namespace std;

int T, N;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int num[100000];
        for (int j = 0; j < N; j++) {
            cin >> num[j];
        }
        int prev = -1;
        bool b = true;
        for (int j = 0; j < N; j++) {
            if (num[j] % 2 == 0) {
                if (num[j] >= prev) {
                    prev = num[j];
                }
                else {
                    b = false;
                    break;
                }
            }
        }
        if (!b) {
            cout << "No" << endl;
            continue;
        }
        prev = -1;
        b = true;
        for (int j = 0; j < N; j++) {
            if (num[j] % 2 == 1) {
                if (num[j] >= prev) {
                    prev = num[j];
                }
                else {
                    b = false;
                    break;
                }
            }
        }
        if (!b) {
            cout << "No" << endl;
        }
        else {
            cout << "Yes" << endl;
        }
    }
}