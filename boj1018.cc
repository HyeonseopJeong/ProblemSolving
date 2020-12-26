#include <iostream>
#include <vector>

using namespace std;

int n, m;
char board[50][50];

int ans = -1;

int check(int r, int c) {
    int cnt = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if( (((i % 2) + (j % 2)) % 2) ^ (board[r + i][c + j] == 'B')) {
                cnt++;
            }
        }
    }

    return min(cnt, 64 - cnt);
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < n - 7; i++) {
        for(int j = 0; j < m - 7; j++) {
            int chck = check(i, j);
            if(ans == -1 || ans > chck) {
                ans = chck;
            }
        }
    }

    cout << ans;
    return 0;
}