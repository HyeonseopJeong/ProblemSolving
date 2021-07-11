// 2-6. 그룹 단어 체커	https://www.acmicpc.net/problem/1316

#include <iostream>
#include <string>
#include <cstring>


using namespace std;

bool isGroup(string s) {
  int mapp[128];
  memset(mapp, 0, sizeof(mapp));
  char cur = 0;
  for(char ch : s) {
    if(cur != ch) {
      if(mapp[ch]) return false;
      else {
        cur = ch;
        mapp[ch] = 1;
      }
    }
  }

  return true;
}


int main() {
  int n; cin >> n;

  int ans = 0;
  while(n--) {
    string s; cin >> s; 

    if(isGroup(s)) ans++;
  }

  cout << ans;

  return 0;
}