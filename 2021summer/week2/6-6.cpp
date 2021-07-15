// 6-6. 시리얼 번호	https://www.acmicpc.net/problem/1431

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getSum(string s) {
  int sum = 0;
  for(const char & ch : s) {
    if('0' <= ch && ch <= '9')
      sum += ch - '0';
  }
  return sum;
}

int main() {
  int n; cin >> n;
  vector<string> v(n);

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }


  for(int i = n - 1; i >= 1; i--) {
    for(int j = 0; j < i; j++) {
      if(v[j].length() > v[j + 1].length()) 
          swap(v[j], v[j + 1]);
      if(v[j].length() != v[j + 1].length()) 
        continue;

      int sum1 = getSum(v[j]);
      int sum2 = getSum(v[j + 1]);

      if(sum1 > sum2)
        swap(v[j], v[j + 1]);
      if(sum1 != sum2)
        continue; 

      if(v[j] > v[j + 1])
        swap(v[j], v[j + 1]);
    }
  }

  for(const string & s : v) {
    cout << s << '\n';
  }

  return 0;
}