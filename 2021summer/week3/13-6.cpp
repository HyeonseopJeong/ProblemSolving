// 13-6. 추 정렬하기	https://www.acmicpc.net/problem/1851

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int mapp[1000001];

vector<int> v1, v2;

vector<vector<int> > sets;
bool vis[100000];


int toV1Idx(int idx) {
  return mapp[v2[idx]];
}

int main() {
  int n; cin >> n;
  v1.resize(n); v2.resize(n);

  for(int i = 0; i < n; i++)
    cin >> v1[i];
  v2 = v1;

  sort(v2.begin(), v2.end());
  
  for(int i = 0; i < n; i++) mapp[v1[i]] = i;

  for(int i2 = 0; i2 < n; i2++) {
    int i1 = toV1Idx(i2);

    if(vis[i1]) continue;
    
    vector<int> s;
    while(i1 != i2) {
      vis[i1] = true;
      s.push_back(v1[i1]);
      i1 = toV1Idx(i1);
    }
    vis[i1] = true;
    s.push_back(v1[i1]);

    sets.push_back(s);
  }

  int ans = 0;
  int gm = v2[0];

  for(int i = 0; i < sets.size(); i++) {
    int s = 0;
    int len = sets[i].size();
    for(int j = 1; j < len; j++)
      s += sets[i][j];
    
    ans += s + min(
      (len - 1) * sets[i][0], 
      (len - 1) * gm + 2 * (gm + sets[i][0])
    );
  }

  cout << ans;

  return 0;
}