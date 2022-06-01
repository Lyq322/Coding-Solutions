#include <iostream>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int goal[8];
bool visited[16777216] = {0};

int vec2int(vector<int> v) {
    int n = 0;
    for (int i = 0; i < 8; i++) {
        n += (v[i] - 1) * (int) pow(8, i);
    }
    return n;
}

int main() {
    for (int i = 0; i < 4; i++) {
        cin >> goal[i];
    }
    for (int i = 7; i > 3; i--) {
        cin >> goal[i];
    }
    queue<pair<string, vector<int>>> q;
    q.push({"", {1, 2, 3, 4, 8, 7, 6, 5}});
	visited[vec2int({1, 2, 3, 4, 8, 7, 6, 5})] = true;
    while (!q.empty()) {
        vector<int> start = q.front().second;
        string s = q.front().first;
        q.pop();
        bool b = true;
        for (int i = 0; i < 8; i++) {
            if (start[i] != goal[i]) b = false;
        }
        if (b) {
            cout << s.size() << endl;
            cout << s << endl;
            break;
        }
        // A
        for (int i = 0; i < 4; i++) {
            int temp = start[i];
            start[i] = start[i + 4];
            start[i + 4] = temp;
        }
        int next = vec2int(start);
		if (!visited[next]) {
            visited[next] = true;
            q.push({s + 'A', start});
        }
        for (int i = 0; i < 4; i++) {
            int temp = start[i];
            start[i] = start[i + 4];
            start[i + 4] = temp;
        }
        // B
        int temp = start[3];
        start[3] = start[2];
        start[2] = start[1];
        start[1] = start[0];
        start[0] = temp;
        temp = start[7];
        start[7] = start[6];
        start[6] = start[5];
        start[5] = start[4];
        start[4] = temp;
        next = vec2int(start);
		if (!visited[next]) {
            visited[next] = true;
            q.push({s + 'B', start});
        }
        temp = start[0];
        start[0] = start[1];
        start[1] = start[2];
        start[2] = start[3];
        start[3] = temp;
        temp = start[4];
        start[4] = start[5];
        start[5] = start[6];
        start[6] = start[7];
        start[7] = temp;
        // C
        temp = start[1];
        start[1] = start[5];
        start[5] = start[6];
        start[6] = start[2];
        start[2] = temp;
        next = vec2int(start);
		if (!visited[next]) {
            visited[next] = true;
            q.push({s + 'C', start});
        }
        temp = start[1];
        start[1] = start[2];
        start[2] = start[6];
        start[6] = start[5];
        start[5] = temp;
    }
}