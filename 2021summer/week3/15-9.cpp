// 15-9. 고득점	https://www.acmicpc.net/problem/3663

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>
#include <cmath>

using namespace std;

int solve() {
  string s; cin >> s;
  int len = s.length();

  int ans = 0;
  for (int i = 0; i < len; i++)
    ans += min(s[i] - 'A', 26 - (s[i] - 'A'));
  
  int move = len - 1;
  int cnt = 0;
  for(int i = 1; i < len; i++) {
    if(s[i] == 'A') {
      cnt++;
    }
    else if(cnt) {
      int a = i - cnt - 1;
      int b = len - i;
      if(a > b) swap(a, b);
      move = min(move, 2 * a + b);
      cnt = 0;
    }
  }

  if(cnt) move = min(move, len - cnt - 1);
  ans += move;

  return ans;
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int T; cin >> T;

  while(T--) {
    cout << solve() << '\n';
  }

  return 0;
}