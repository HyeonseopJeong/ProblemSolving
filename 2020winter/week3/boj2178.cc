#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[100][100];
int R, C;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            char tmp;
            cin >> tmp;
            arr[i][j] = tmp - '0';
        }
    }   

    queue<pair<pair<int, int>, int>> qu;

    arr[0][0] = -1; qu.push({{0, 0}, 1});

    int ans = 0;
    while(!qu.empty()) {
        pair<pair<int, int>, int> cur = qu.front(); qu.pop();
        
        if(cur.first.first == R - 1 && cur.first.second == C - 1) {
            ans = cur.second;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nr = cur.first.first + dr[i];
            int nc = cur.first.second + dc[i];
            if(nr >= 0 && nc >= 0 && nr < R && nc < C && arr[nr][nc] == 1) {
                arr[nr][nc] = -1; qu.push({{nr, nc}, cur.second + 1});
            }
        }
    }

    cout << ans;
    return 0;
}