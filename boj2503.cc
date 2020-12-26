#include <iostream>
#include <vector>

using namespace std;

bool candidate[1000];

bool is_able(int n) {
    if(n == 0)
        return false;
    
    int check[10] = {0, };

    for(int i = 0; i < 3; i++) {
        if(check[n % 10] || n % 10 == 0)
            return false;
        check[n % 10] = 1;
        n /= 10;
    }

    return true;
}


void f(int n, int s, int b) {
    for(int m = 111; m < 1000; m++) {
        if(!candidate[m])
            continue;
        int ss = 0, bb = 0;

        int x[3] = {n % 10, (n / 10) % 10, (n / 100)};
        int y[3] = {m % 10, (m / 10) % 10, (m / 100)};

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(i == j && x[i] == y[j])
                    ss++;
                if(i != j && x[i] == y[j])
                    bb++;   
            }
        }
        
        if(s != ss || b != bb)
            candidate[m] = 0;
    }
}


int main() {
    for(int i = 111; i < 1000; i++)
        if(is_able(i))
            candidate[i] = 1;
    
    int n;  cin >> n;

    while(n--) {
        int num, s, b;
        cin >> num >> s >> b;
        f(num, s, b);
    }

    int cnt = 0;
    for(int i = 111; i < 1000; i++) {
        if(candidate[i])
            cnt++;
    }

    cout << cnt;
    return 0;
}