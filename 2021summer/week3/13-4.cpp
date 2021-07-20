// 13-4. 방탈출	https://www.acmicpc.net/problem/15729

#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  vector<bool> v(n);
  vector<bool> v2(n);

  for(int i = 0; i < n; i++) {
    int tmp; cin >> tmp;
    v[i] = tmp;
  }


  int cnt = 0;
  for(int i = 0; i < n; i++) {
    if(v[i] != v2[i]) {
      cnt++;
      for(int j = 0; j < 3 && i + j < n; j++) 
        v2[i + j] = !v2[i + j];
    }
  }

  cout << cnt;
}
