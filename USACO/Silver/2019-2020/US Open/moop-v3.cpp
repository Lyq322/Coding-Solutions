#include <bits/stdc++.h>

using namespace std;
typedef pair<int,  int> pii;

ifstream fin;
ofstream fout;

int N;
pii cows[100000];

int main() {
    fin.open("moop.in");
    fout.open("moop.out");
	fin >> N;
    for (int i = 0; i < N; i++) {
        fin >> cows[i].first >> cows[i].second;
    }
    sort(cows, cows + N);
    stack<pii> s;
    for (int i = 0; i < N; i++) {
        s.push({cows[i].second, cows[i].second});
        while (s.size() >= 2) {
            pii fir = s.top();
            s.pop();
            pii sec = s.top();
            if (fir.first >= sec.second) {
                s.pop();
                s.push({max(fir.first, sec.first), min(fir.second, sec.second)});
            }
            else {
                s.push(fir);
                break;
            }
        }
    }
    fout << s.size() << endl;
}
