#include <iostream>

using namespace std;

int star[2000][2000];

int pow2(int p) {
    return 1 << p;
}

void semo(int y, int x) {
    star[y][x] = 1;
    star[y][x + 1] = 1;
    star[y][x + 2] = 1;
    star[y][x + 3] = 1;

    star[y + 1][x] = 1;
    star[y + 1][x + 2] = 1;
    star[y + 2][x] = 1;
    star[y + 2][x + 1] = 1;

    star[y + 3][x] = 1;
}

void f(int y, int x, int n) {
    if(n == 2) {
        semo(y, x);
        return;
    }

    f(y, x, n - 1);
    f(y + pow2(n - 1), x, n - 1);
    f(y, x + pow2(n - 1), n - 1);
}

int main() {
    int n;
    cin >> n;

    if(n == 0) {
        printf("*");
    }
    else if(n == 1) {
        printf("**\n*");
    }
    else {
        f(0, 0, n);
        for(int i = 0; i < pow2(n); i++) {
            for(int j = 0; j < pow2(n) - i; j++) {
                if(star[i][j])
                    printf("*");
                else   
                    printf(" ");
            }
            printf("\n");
        }
    }

}