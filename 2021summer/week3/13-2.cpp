// 13-2. 잃어버린 괄호	https://www.acmicpc.net/problem/1541

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> nums;
vector<char> ops;

int main() {
  string s; cin >> s;

  int prev_i = 0;
  for(int i = 0; i < s.length(); i++) {
    if(s[i] == '+' || s[i] == '-') {
      ops.push_back(s[i]);

      int n = stoi(s.substr(prev_i, i - prev_i));
      nums.push_back(n);

      prev_i = i + 1;
    }
  }
  nums.push_back(stoi(s.substr(prev_i, s.length() - prev_i)));

  int ans = nums[0];
  int check = 0;

  for(int i = 0; i < ops.size(); i++) {
    if(ops[i] == '-') check = 1;
    if(check) ans -= nums[i + 1];
    else ans += nums[i + 1];
  }

  cout << ans;

  return 0;
}