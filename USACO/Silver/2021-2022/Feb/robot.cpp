#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    int m;
};

int N;
pair<int, int> moves[40];
pair<int, int> finish;
vector<Point> l;
vector<Point> r;

void choose1(string s) {
    if (s.length() == N / 2) {
        pair<int, int> p = {0, 0};
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '1') {
				p.first += moves[i].first;
                p.second += moves[i].second;
                count++;
            }
        }
        l.push_back({p.first, p.second, count});
        return;
    }
    choose1(s + '0');
    choose1(s + '1');
}

void choose2(string s) {
    if (s.length() == N - N / 2) {
        pair<int, int> p = finish;
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.at(i) == '1') {
                p.first -= moves[N / 2 + i].first;
                p.second -= moves[N / 2 + i].second;
                count++;
            }
        }
        r.push_back({p.first, p.second, count});
        return;
    }
    choose2(s + '0');
    choose2(s + '1');
}

bool comp(Point a, Point b) {
    if (a.x == b.x) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

int main() {
    cin >> N;
    cin >> finish.first >> finish.second;
    for (int i = 0; i < N; i++) {
        cin >> moves[i].first >> moves[i].second;
    }
    choose1("");
    choose2("");
    sort(l.begin(), l.end(), comp);
    sort(r.begin(), r.end(), comp);
    int lIndex = 0;
    int rIndex = 0;
    int ans[41] = {0};
    while (lIndex < l.size() - 1 || rIndex < r.size() - 1) {
        if (l[lIndex].x == r[rIndex].x && l[lIndex].y == r[rIndex].y) {
            for (int i = lIndex; i < l.size(); i++) {
                for (int j = rIndex; j < r.size(); j++) {
                    ans[l[i].m + r[j].m]++;
                    if (j == r.size() - 1 || r[j].x != r[j + 1].x || r[j].y != r[j + 1].y) {
                        break;
                    }
                }
                if (i == l.size() - 1 || l[i].x != l[i + 1].x || l[i].y != l[i + 1].y) {
                    break;
                }
            }
            while (lIndex < l.size()) {
                if (lIndex == l.size() - 1) {
                    break;
                }
                else if (l[lIndex].x != l[lIndex + 1].x || l[lIndex].y != l[lIndex + 1].y) {
                    lIndex++;
                    break;
                }
                lIndex++;
            }
            while (rIndex < r.size()) {
                if (rIndex == r.size() - 1) {
                    break;
                }
                else if (r[rIndex].x != r[rIndex + 1].x || r[rIndex].y != r[rIndex + 1].y) {
                    rIndex++;
                    break;
                }
                rIndex++;
            }
        }
        else if (l[lIndex].x < r[rIndex].x) {
            if (lIndex == l.size() - 1) {
                break;
            }
            lIndex++;
        }
        else if (l[lIndex].x > r[rIndex].x) {
            if (rIndex == r.size() - 1) {
                break;
            }
            rIndex++;
        }
		else if (l[lIndex].y < r[rIndex].y) {
			if (lIndex == l.size() - 1) {
				break;
			}
			lIndex++;
		}
		else if (l[lIndex].y > r[rIndex].y) {
			if (rIndex == r.size() - 1) {
				break;
			}
			rIndex++;
		}
    }
    for (int i = 1; i <= N; i++) {
        cout << ans[i] << endl;
    }
}