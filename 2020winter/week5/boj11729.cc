#include <cstdio>

using namespace std;

void f(int from, int to, int n) {
    if(n == 1) {
        printf("%d %d\n", from, to);
        return;
    }

    int tmp = 6 - from - to;

    f(from, tmp, n - 1);
    f(from, to, 1);
    f(tmp, to, n - 1);
}

int pow2(int p) {
    return 1 << p;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", pow2(n) - 1);

    f(1, 3, n);
    return 0;
}