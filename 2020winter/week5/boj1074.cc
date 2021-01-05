#include <iostream>

using namespace std;

int Y, X;

int dy[] = {0, 0, 1, 1};
int dx[] = {0, 1, 0, 1};

int pow2(int p) {
    return 1 << p;
}

void find(int y, int x, int cnt, int n) {
    if(y == Y && x == X) {
        cout << cnt;
        return;
    }

    if(Y < y + pow2(n - 1)) {
        if(X < x + pow2(n - 1)) {
            find(y, x, cnt, n - 1);
        }
        else {
            find(y, x + pow2(n - 1), cnt + pow2((n - 1) * 2), n - 1);
        }  
    }
    else {
        if(X < x + pow2(n - 1)) {
            find(y + pow2(n - 1), x, cnt + pow2((n - 1) * 2) * 2, n - 1);
        }
        else {
            find(y + pow2(n - 1), x + pow2(n - 1), cnt + pow2((n - 1) * 2) * 3, n - 1);
        }  
    }
}

int main() {
    int n;
    cin >> n >> Y >> X;

    find(0, 0, 0, n);

    return 0;
}