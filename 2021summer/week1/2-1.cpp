// 2-1. 비밀번호 발음하기	https://www.acmicpc.net/problem/4659

#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string vowels = "aeiou";

bool check1(string s) {
  for(const char & ch : s)
    for(const char & vw : vowels)
      if(ch == vw)
        return true;

  return false;
}

bool check2(string s) {
  int cntC = 0, cntV = 0;

  for(const char & ch : s) {
    bool isVowel = false;
    for(const char & vw : vowels) {
      if(ch == vw) {
        isVowel = true;
      }
    }
    if(isVowel) {
      cntC = 0; 
      cntV++;
    } else {
      cntV = 0; 
      cntC++;
    }

    if(cntC >= 3 || cntV >= 3)
      return false;
  }

  return true;
}

bool check3(string s) {
  for(int i = 1; i < s.length(); i++) {
    if(s[i - 1] == s[i] 
      && s[i] != 'e' 
      && s[i] != 'o'
    )
      return false;
  }
  return true;
}

int main() {
  while(1) {
    string str; cin >> str;
    if(str == "end") break;

    if(check1(str) && check2(str) && check3(str))
      printf("<%s> is acceptable.\n", str.c_str());
    else
      printf("<%s> is not acceptable.\n", str.c_str());
  }
  return 0;
}