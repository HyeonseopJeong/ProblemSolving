#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int ans;
vector<string> sv;

int check() {
    int ret = 0;
    
    for(int y = 0; y < n; y++) {
        for(int x = 0; x < n; x++) {
            int cnt = 1;
            //가로
            for(int i = 1; ; i++) {
                if(x + i >= n || sv[y][x + i] != sv[y][x])
                    break;
                cnt++;
            }
            for(int i = 1; ; i++) {
                if(x - i < 0 || sv[y][x - i] != sv[y][x])
                    break;
                cnt++;
            }
            ret = max(ret, cnt);
            cnt = 1;

            //세로
            for(int i = 1; ; i++) {
                if(y + i >= n || sv[y + i][x] != sv[y][x])
                    break;
                cnt++;
            }
            for(int i = 1; ; i++) {
                if(y - i < 0 || sv[y - i][x] != sv[y][x])
                    break;
                cnt++;
            }

            ret = max(ret, cnt);            
        }
    }

    return ret;
}


int main() {
    cin >> n;   sv.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> sv[i];
    }

    ans = max(ans, check());

    for(int y = 0; y < n - 1; y++) {
        for(int x = 0; x < n; x++) {
            if(x < n - 1) {
                swap(sv[y][x], sv[y][x + 1]);
                ans = max(ans, check());
                swap(sv[y][x], sv[y][x + 1]);
            }
            swap(sv[y][x], sv[y + 1][x]);
            ans = max(ans, check());
            swap(sv[y][x], sv[y + 1][x]);   
        }
    }

    cout << ans;

    return 0;
}