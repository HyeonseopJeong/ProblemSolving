// 12-6. 피보나치 수	https://www.acmicpc.net/problem/4150

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string mem[5001];

string plusString(string s1, string s2) {
  string ans;
  if(s1.length() < s2.length()) swap(s1, s2);
  
  reverse(s1.begin(), s1.end());
  reverse(s2.begin(), s2.end());

  int len = s1.length();

  int carry = 0;

  for(int i = 0; i < len; i++) {
    int sum = s1[i] - '0';

    if(i < s2.length()) 
      sum += s2[i] - '0';
    if(carry) 
      sum += 1;
    
    if(sum >= 10) {
      carry = 1;
      sum -= 10;
    }
    else {
      carry = 0;
    }

    ans.push_back((char)(sum + '0'));
  }

  if(carry) {
    ans.push_back('1');
  }
  
  reverse(ans.begin(), ans.end());
  return ans;
}

string f(string s) {
  if(s == "1" || s == "2")
    return "1";

  int n = stoi(s);

  if(mem[n] != "") {
    return mem[n];
  }
    
  mem[n] = plusString(f(to_string(n - 1)), f(to_string(n - 2)));
  return mem[n];
}

int main() {
  string s; cin >> s;
  cout << f(s);
  return 0;
}