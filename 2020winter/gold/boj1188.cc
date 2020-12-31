//1188 음식 평론가

#include <iostream>
#include <cstring>

using namespace std;

int mem[101][101];

int f(int n, int m) {
    if(n == m)
        return 0;

    if(mem[n][m] != -1)
        return mem[n][m];
    if(n > m)
        return mem[n][m] = f(n - m, m);
    return mem[n][m] = n + f(n, m - n);
}

int main() {
    memset(mem, -1, sizeof(mem));

    int n, m;
    cin >> n >> m;
    cout << f(n, m);
    return 0;
}