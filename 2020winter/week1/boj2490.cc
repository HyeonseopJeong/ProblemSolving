#include <bits/stdc++.h>

using namespace std;

int main() {

    for(int i = 0; i < 3; i++) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            int state;  cin >> state;
            cnt += state;
        }
        if(cnt == 0)
            cout << "D\n";    //윷
        else if(cnt == 1)
            cout << "C\n";    //걸
        else if(cnt == 2)
            cout << "B\n";    //개
        else if(cnt == 3)
            cout << "A\n";    //도
        else if(cnt == 4)
            cout << "E\n";    //모
    }

    return 0;
}