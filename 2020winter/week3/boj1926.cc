#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int arr[500][500];
int R, C;

int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int bfs(int r, int c) {
    int ret = 0;
    queue<pair<int, int>> qu;
    arr[r][c] = -1; qu.push({r, c}); ret++;

    while(!qu.empty()) {
        pair<int, int> cur = qu.front(); qu.pop();
        for(int i = 0; i < 4; i++) {
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if(nr >= 0 && nc >= 0 && nr < R && nc < C && arr[nr][nc] == 1) {
                arr[nr][nc] = -1; qu.push({nr, nc}); ret++;
            }
        }
    }

    return ret;
}

int main() {
    cin >> R >> C;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            cin >> arr[i][j];
        }
    }   

    int max_size = 0, num = 0;
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            if(arr[i][j] == 1) {
                max_size = max(max_size, bfs(i, j));
                num++;
            }
        }
    }
    cout << num << '\n' << max_size;

    return 0;
}