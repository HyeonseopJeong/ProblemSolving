// 3-4. 문문문	https://www.acmicpc.net/problem/17210

#include <iostream>

using namespace std;

int main() {
  int n, k; 
  cin >> n >> k;

  if(n >= 6) cout << "Love is open door";
  else
    for(int i = 1; i < n; i++) {
      k = !k;
      cout << k << '\n';
    }

  return 0;
}