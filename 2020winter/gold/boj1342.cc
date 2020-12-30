#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int is_lucky(const string & s) {
    int len = s.length();
    for(int i = 0; i < len - 1; i++)
        if(s[i] == s[i + 1])
            return 0;
    return 1;
}

int main() {

    int ans = 0;
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    do {
        ans += is_lucky(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << ans;

    return 0;
}