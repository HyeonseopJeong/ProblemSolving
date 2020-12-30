#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        int tmp;    cin >> tmp;
        if(tmp < m)
            cout << tmp << ' ';
    }

    return 0;
}