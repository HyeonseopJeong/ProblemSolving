// 15-8. 오르막길	https://www.acmicpc.net/problem/2846

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n; cin >>n;
  vector<int> v(n);

  for(int i = 0; i < n; i++) cin >> v[i];

  v.push_back(0);

  int ans = 0, floor = v[0];

  for(int i = 1; i < v.size(); i++) {
    if(v[i - 1] < v[i]) continue;

    ans = max(ans, v[i - 1] - floor);
    floor = v[i];
  }

  cout << ans;
  
  return 0;
}

