//1629 곱셈

#include <iostream>

using namespace std;

long long a, b, c = 1;

long long pow(long long n, long long m) {
    if(m == 1)
        return n % c;
    
    long long k = pow(n, m / 2);
    long long ret = (k * k) % c;
    if(m % 2 == 0)
        return ret;
    else
        return (ret * n) % c;
}

int main() {
    cin >> a >> b >> c;
    cout << pow(a, b);
    return 0;
}