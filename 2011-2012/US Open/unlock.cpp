#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

struct state {
  int x1, y1, x2, y2;
};

int n1, n2, n3;

vector<pii> piece1;
vector<pii> piece2;
vector<pii> piece3;

int dx1[12] = {1, 0, 0, 0, 1, -1, -1, 0, 0, 0, 1, 0};
int dy1[12] = {0, 1, 0, 0, 0, 0, 0, -1, 0, 0, 0, -1};
int dx2[12] = {0, 0, 1, 0, 1, -1, 0, 0, -1, 0, 1, 0};
int dy2[12] = {0, 0, 0, 1, 0, 0, 0, 0, 0, -1, 0, -1};

int moves[41][41][41][41];
bool visited[41][41][41][41];

int x1_min = 9, x1_max = 0, y1_min = 9, y1_max = 0;
int x2_min = 9, x2_max = 0, y2_min = 9, y2_max = 0;
int x3_min = 9, x3_max = 0, y3_min = 9, y3_max = 0;

bool overlap(int p1, int p2, state s) {
  // Piece 1 and 2
  if (p1 == 1 && p2 == 2) {
    for (int i = 0; i < piece1.size(); i++) {
      int newx1 = s.x1 + piece1[i].first;
      int newy1 = s.y1 + piece1[i].second;
      for (int j = 0; j < piece2.size(); j++) {
        int newx2 = s.x2 + piece2[j].first;
        int newy2 = s.y2 + piece2[j].second;
        if (newx1 == newx2 && newy1 == newy2) {
          return true;
        }
      }
    }
  }
  // Piece 2 and 3
  else if (p1 == 1 && p2 == 3) {
    for (int i = 0; i < piece1.size(); i++) {
      int newx1 = s.x1 + piece1[i].first;
      int newy1 = s.y1 + piece1[i].second;
      for (int j = 0; j < piece3.size(); j++) {
        if (newx1 == piece3[j].first && newy1 == piece3[j].second) {
          return true;
        }
      }
    }
  }
  // Piece 1 and 3
  else {
    for (int i = 0; i < piece2.size(); i++) {
      int newx2 = s.x2 + piece2[i].first;
      int newy2 = s.y2 + piece2[i].second;
      for (int j = 0; j < piece3.size(); j++) {
        if (newx2 == piece3[j].first && newy2 == piece3[j].second) {
          return true;
        }
      }
    }
  }
  return false;
}

bool separated(state s) {
  bool onetwo = false;
  bool twothree = false;
  bool onethree = false;

  int newx1_min = x1_min + s.x1;
  int newx1_max = x1_max + s.x1;
  int newy1_min = y1_min + s.y1;
  int newy1_max = y1_max + s.y1;

  int newx2_min = x2_min + s.x2;
  int newx2_max = x2_max + s.x2;
  int newy2_min = y2_min + s.y2;
  int newy2_max = y2_max + s.y2;

  // Piece 1 and 2
  if (newx1_min > newx2_max || newx1_max < newx2_min || newy1_min > newy2_max || newy1_max < newy2_min) {
    onetwo = true;
  }
  // Piece 2 and 3
  if (newx2_min > x3_max || newx2_max < x3_min || newy2_min > y3_max || newy2_max < y3_min) {
    twothree = true;
  }
  // Piece 1 and 3
  if (newx1_min > x3_max || newx1_max < x3_min || newy1_min > y3_max || newy1_max < y3_min) {
    onethree = true;
  }
  
  if (onetwo && twothree && onethree) {
    return true;
  }
  return false;
}

int main() {
  cin >> n1 >> n2 >> n3;
  int a, b;

  // Piece 1;
  for (int i = 0; i < n1; i++) {
    cin >> a >> b;
    piece1.push_back({a + 20, b + 20});
    if (x1_min > a) {
      x1_min = a;
    }
    if (x1_max < a) {
      x1_max = a;
    }
    if (y1_min > b) {
      y1_min = b;
    }
    if (y1_max < b) {
      y1_max = b;
    }
  }
  // Piece 2
  for (int i = 0; i < n2; i++) {
    cin >> a >> b;
    piece2.push_back({a + 20, b + 20});
    if (x2_min > a) {
      x2_min = a;
    }
    if (x2_max < a) {
      x2_max = a;
    }
    if (y2_min > b) {
      y2_min = b;
    }
    if (y2_max < b) {
      y2_max = b;
    }
  }
  // Piece 3
  for (int i = 0; i < n3; i++) {
    cin >> a >> b;
    piece3.push_back({a + 20, b + 20});
    if (x3_min > a) {
      x3_min = a;
    }
    if (x3_max < a) {
      x3_max = a;
    }
    if (y3_min > b) {
      y3_min = b;
    }
    if (y3_max < b) {
      y3_max = b;
    }
  }

  moves[20][20][20][20] = 0;
  for (int i = 0; i < 41; i++) {
    for (int j = 0; j < 41; j++) {
      for (int k = 0; k < 41; k++) {
        for (int l = 0; l < 41; l++) {
          visited[i][j][k][l] = false;
        }
      }
    }
  }
  visited[20][20][20][20] = true;

  queue<state> q;
  q.push({0, 0, 0, 0});
  bool found = false;

  while (!q.empty()) {
    state current = q.front();
    q.pop();
    for (int i = 0; i < 12; i++) {
      state new_state = {
        current.x1 + dx1[i], 
        current.y1 + dy1[i],
        current.x2 + dx2[i], 
        current.y2 + dy2[i]
      };
      if (new_state.x1 >= -20 && new_state.x1 <= 20 && new_state.x2 >= -20 && new_state.x2 <= 20 && new_state.y1 >= -20 && new_state.y1 <= 20 && new_state.y2 >= -20 && new_state.y2 <= 20 && !visited[new_state.x1 + 20][new_state.y1 + 20][new_state.x2 + 20][new_state.y2 + 20] && !overlap(1, 2, new_state) && !overlap(2, 3, new_state) && !overlap(1, 3, new_state)) {
        visited[new_state.x1 + 20][new_state.y1 + 20][new_state.x2 + 20][new_state.y2 + 20] = true;
        moves[new_state.x1 + 20][new_state.y1 + 20][new_state.x2 + 20][new_state.y2 + 20] = moves[current.x1 + 20][current.y1 + 20][current.x2 + 20][current.y2 + 20] + 1;
        if (separated(new_state)) {
          int ans = moves[new_state.x1 + 20][new_state.y1 + 20][new_state.x2 + 20][new_state.y2 + 20];
          cout << ans << endl;
          found = true;
          break;
        }
        q.push(new_state);
      }
    }
    if (found) {
      break;
    }
  }
  if (!found) {
    cout << -1 << endl;
  }
} 