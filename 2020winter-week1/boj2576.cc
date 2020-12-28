#include <bits/stdc++.h>

using namespace std;

int main() {
    int sum = 0, min_odd = -1;

    for (int i = 0; i < 7; i++) {
        int num;
        cin >> num;
        if(num % 2) {
            sum += num;
            if(min_odd == -1 || min_odd > num)
                min_odd = num;
        }
    }

    if(min_odd == -1)
        cout << -1;
    else
        cout << sum << '\n' << min_odd;

    return 0;
}