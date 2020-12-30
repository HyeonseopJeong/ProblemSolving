#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if(a == b && b == c) 
        cout << 10000 + a * 1000;
    else if(a == b || a == c || b == c) {
        if(b == c) swap(a, c);
        cout << 1000 + a * 100;
    }
    else {
        cout << max({a, b, c}) * 100;
    }
    return 0;
}