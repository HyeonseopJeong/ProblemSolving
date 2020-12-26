#include <iostream>

using namespace std;

int n, s, arr[20];

int f(int idx, int sum) {
    if(idx == n)
        return sum == s;
    int ret = 0;
    ret += f(idx + 1, sum + arr[idx]);
    ret += f(idx + 1, sum);

    return ret;
}


int main() {
    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << f(0, 0) - (s == 0);
    return 0;
}