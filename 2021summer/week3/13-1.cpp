// 13-1. 동전 0	https://www.acmicpc.net/problem/11047

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n) ;

  for(int i = 0; i < n; i++) cin >> v[i];
  
  int ans = 0;
  while(k) {
    for(int i = n - 1; i >= 0; i--) {
      if(v[i] <= k) {
        k -= v[i];
        ans++;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}