// 2-4. 다이얼	https://www.acmicpc.net/problem/5622

#include <iostream>
#include <string>

using namespace std;

int getCount(char ch) {
  if(ch == 'A' || ch == 'B' || ch == 'C') {
    return 3;
  } else if(ch == 'D' || ch == 'E' || ch == 'F') {
    return 4;
  } else if(ch == 'G' || ch == 'H' || ch == 'I') {
    return 5;
  } else if(ch == 'J' || ch == 'K' || ch == 'L') {
    return 6;
  } else if(ch == 'M' || ch == 'N' || ch == 'O') {
    return 7;
  } else if(ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S') {
    return 8;
  } else if(ch == 'T' || ch == 'U' || ch == 'V') {
    return 9;
  } else if(ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z') {
    return 10;
  }
  return 0;
} 

int main() {
  string s; cin >> s;
  
  int ans = 0;
  for(char ch : s) {
    ans += getCount(ch);
  }
  cout << ans;

  return 0;
}