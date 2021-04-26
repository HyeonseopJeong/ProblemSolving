#include <iostream>

using namespace std;

inline int f(int n) {
    return (n * (n + 1)) / 2;
}

int main() {
    int tc;

    cin >> tc;

    while(tc--) {
        int n;  cin >> n;
        int check = 0;
        for(int i = 1; i < 100 && !check; i++) {
            for(int j = 1; j < 100 && !check; j++) {
                for(int k = 1; k < 100 && !check; k++) {
                    if(f(i) + f(j) + f(k) == n)
                        check = 1;
                }
            }
        }
        cout << check << '\n';
    }


    return 0;
}