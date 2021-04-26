#include <iostream>

using namespace std;

int generate(int n) {
    int ret = n;
    while(n) {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

int main () {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        if(generate(i) == n) {
            cout << i;
            return 0;
        }
    }
    
    cout << 0;
    return 0;
}