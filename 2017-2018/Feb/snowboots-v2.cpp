#include <iostream>
#include <algorithm>

using namespace std;
     
int N, B;
int tiles[250];
int depth[250];
int distances[250];
int ans = 9999;

bool visited[250][250];
 
void graph(int pos, int boot) {
  if (pos == N-1) { 
    ans = min(ans, boot); 
    return; 
  }
   for (int i = pos+1; i < N; i++) {
    if (tiles[i] <= depth[boot] && !visited[i][boot] && i - pos <= distances[boot]) {
      visited[i][boot] = true;
      graph(i,boot);
    } 
  }
  for (int b = boot+1; b<B; b++) {
    if (tiles[pos] <= depth[b] && !visited[pos][b]) {
      visited[pos][b] = true;
      graph(pos,b);
    }
  }
}
     
int main(void) {
  cin >> N >> B;
  for (int i = 0; i < N; i++) {
    cin >> tiles[i];
  }
  for (int i = 0; i < B; i++) {
    cin >> depth[i] >> distances[i];
  }
  graph(0, 0);
  cout << ans << "\n";
}