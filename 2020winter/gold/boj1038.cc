//1038 감소하는 수
#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> vv(11);
int cnt;


bool isDone() {
    if(!cnt)
        return true;
    cnt--;
    return false;
}


int main() {
    cin >> cnt;
    
    //basecase
    for(int i = 0; i <= 9; i++) {
        vv[1].push_back(i);
        if(isDone()) {
            cout << i;
            return 0;
        }
    }
    
    for(int nDigit = 2; nDigit <= 10; nDigit++) {
        for(const long long & x: vv[nDigit - 1]) {
            for(int i = 0; i < x % 10; i++) {
                vv[nDigit].push_back(x * 10 + i);
                if(isDone()) {
                    cout << x * 10 + i;
                    return 0;
                }
            }
        }
    }

    cout << -1;
    return 0;
}

