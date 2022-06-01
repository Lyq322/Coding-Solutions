#include <iostream>
#include <vector>

using namespace std;

int N, M;
int donuts[100000];
vector<vector<int>> needFirst;
vector<vector<int>> needSecond;
pair<int, int> cows[100000];

int main() {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        needFirst.push_back({});
        needSecond.push_back({});
    }
    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
        cows[i].first--;
        cows[i].second--;
    }
    int taken[100000] = {0};
    for (int i = 0; i < N; i++) {
        if (taken[cows[i].first] == 0) {
            taken[cows[i].first] = 1;
            donuts[i] = 0;
        }
        else if (taken[cows[i].second] == 0) {
            taken[cows[i].second] = 1;
            donuts[i] = 1;
            needFirst[cows[i].first].push_back(i);
        }
        else {
            donuts[i] = -1;
            needFirst[cows[i].first].push_back(i);
            needSecond[cows[i].second].push_back(i);
        }
    }
    int total = 0;
    for (int i = 0; i < N; i++) {
        if (donuts[i] != -1) {
            total++;
        }
    }
    cout << total << endl;
    for (int i = 0; i < N - 1; i++) {
        int freeDonut;
        if (donuts[i] == 0) {
            freeDonut = cows[i].first;
        }
        else {
            freeDonut = cows[i].second;
            needFirst[cows[i].first].erase(needFirst[cows[i].first].begin());
        }
        total--;
        while (true) {
            int firstNeed = N;
            int secondNeed = N;
            if (needFirst[freeDonut].size() > 0) {
                firstNeed = needFirst[freeDonut][0];
            }
            if (needSecond[freeDonut].size() > 0) {
                secondNeed = needSecond[freeDonut][0];
            }
            if (firstNeed < secondNeed) {
                if (donuts[firstNeed] == 1) {
                    needFirst[freeDonut].erase(needFirst[freeDonut].begin());
                    freeDonut = cows[firstNeed].second;
                    donuts[firstNeed] = 0;
                }
                else {
                    total++;
                    donuts[firstNeed] = 0;
                    needFirst[freeDonut].erase(needFirst[freeDonut].begin());
                    needSecond[cows[firstNeed].second].erase(lower_bound(needSecond[cows[firstNeed].second].begin(), needSecond[cows[firstNeed].second].end(), firstNeed));
                    break;
                }
            }
            else if (firstNeed > secondNeed) {
                total++;
                needSecond[freeDonut].erase(needSecond[freeDonut].begin());
                donuts[secondNeed] = 1;
                break;
            }
            else {
                break;
            }
            
        }
        cout << total << endl;
    }
}