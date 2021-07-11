// 3-3. 카이사르 암호	https://www.acmicpc.net/problem/5598

#include <iostream>
#include <string>

using namespace std;

string decode(string s) {
  string decoded;
  for(int i = 0; i < s.length(); i++) {
    char ch = ((s[i] - 'A' + 26) - 3) % 26 + 'A';
    decoded.push_back(ch);
  }
  return decoded;
}

int main() {
  string s; cin >> s;

  cout << decode(s);
  return 0;
}