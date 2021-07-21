// 13-5. DNA 발견	https://www.acmicpc.net/problem/2806

#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

int pre[2], cur[2];


int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >> n;
  string s; cin >> s;

  cur[0] = !!(s[0] != 'A');
  cur[1] = !!(s[0] != 'B');

  for(int i = 1; i < n; i++) {
    pre[0] = cur[0];
    pre[1] = cur[1];

    cur[0] = min(
      pre[0] + !!(s[i] != 'A'),
      pre[1] + !!(s[i] != 'B') + 1
    );
    
    cur[1] = min(
      pre[1] + !!(s[i] != 'B'),
      pre[0] + !!(s[i] != 'A') + 1
    );
  }

  cout << cur[0];

  return 0;
}