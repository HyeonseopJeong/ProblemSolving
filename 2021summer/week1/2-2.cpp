// 2-2. OX퀴즈	https://www.acmicpc.net/problem/8958

#include <iostream>
#include <string>

using namespace std;

int main() {
  int tc; cin >> tc;

  while(tc--) {
    string s;
    cin >> s;
    int cnt, score;
    cnt = score = 0;

    for(const char & ch : s) {
      if(ch == 'O') score += ++cnt;
      else cnt = 0;
    }

    cout << score << '\n';
  }

  return 0;
}