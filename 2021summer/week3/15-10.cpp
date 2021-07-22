// 15-10. 듣보잡	https://www.acmicpc.net/problem/1764

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<string> s1(n);
  vector<string> s2(m);

  for(int i = 0; i < n; i++) cin >> s1[i];
  for(int i = 0; i < m; i++) cin >> s2[i];

  sort(s1.begin(), s1.end());
  sort(s2.begin(), s2.end());

  vector<string> ans;

  int i = 0, j = 0;
  while(i < n && j < m) {
    if(s1[i] < s2[j]) i++;
    else if(s1[i] > s2[j]) j++;
    else {
      ans.push_back(s1[i]);
      i++; j++;
    }
  }

  cout << ans.size() << '\n';
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i] << '\n';
  
  return 0;
}
