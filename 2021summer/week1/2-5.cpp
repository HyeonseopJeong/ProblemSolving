// 2-5. 단어 공부	https://www.acmicpc.net/problem/1157

#include <iostream>
#include <string>
#include <vector>

using namespace std;

char toCapital(char ch) {
  if('a' <= ch && ch <= 'z')
    return ch - 'a' + 'A';
  return ch;
}


int counts[128] = {0, };

int main() {
  string s; cin >> s;
  for(int i = 0; i < s.length(); i++) {
    counts[toCapital(s[i])] += 1;
  }

  int maxCnt = 0;
  char maxChar;

  for(int ch = 'A'; ch <= 'Z'; ch++) {
    if(counts[ch] > maxCnt) {
      maxCnt = counts[ch];
      maxChar = (char)ch;
    } else if(counts[ch] == maxCnt) {
      maxChar = '?';
    }
  }

  cout << maxChar;

  return 0;
}