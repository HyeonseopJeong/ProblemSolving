#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a > b)
        swap(a, b);
    if(b > c)
        swap(b, c);
    if(a > b)
        swap(a, b);

    printf("%d %d %d", a, b, c);

    return 0;
}