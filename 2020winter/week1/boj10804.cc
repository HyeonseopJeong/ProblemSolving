#include <bits/stdc++.h>

using namespace std;

vector<int> v(20);

int main() {
    for(int i = 0; i < 20; i++)
        v[i] = i + 1;
    

    for(int i = 0; i < 10; i++) {
        int a, b;   cin >> a >> b;
        for(int j = 0; j < (b - a + 1) / 2; j++)
            swap(v[a - 1 + j], v[b - 1 - j]);
    }

    for(int i = 0; i < 20; i++)
        cout << v[i] << ' ';

    return 0;
}