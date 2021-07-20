// 13-3. 스네이크버드	https://www.acmicpc.net/problem/16435

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n, len;
  cin >> n >> len;

  vector<int> v(n);

  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  for(int i = 0; i < v.size(); i++) {
    if(v[i] <= len) len++;
    else break;
  }

  cout << len;

  return 0;
}