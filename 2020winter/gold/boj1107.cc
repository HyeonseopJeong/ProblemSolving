// 1107 리모컨
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int num[10] = {1,1,1,1,1,1,1,1,1,1};

bool isPossible(int n) {
    if(n == 0)
        return num[n];

    while(n) {
        if(!num[n % 10])
            return false;
        n /= 10;
    }
    return true;
}

int getNDigit(int num) {
    if(num == 0)
        return 1;
    
    int cnt = 0;
    while(num != 0) {
        cnt++;
        num /= 10;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    
    int m; cin >> m;
    while(m--) {
        int no; cin >> no;  
        num[no] = 0;
    }

    int ans = abs(n - 100);

    for(int i = 0; i < 1000000; i++) {
        if(isPossible(i)) {
            int tmp = abs(i - n) + getNDigit(i);
            ans = ans > tmp ? tmp : ans;
        }
    }

    cout << ans;

    return 0;
}