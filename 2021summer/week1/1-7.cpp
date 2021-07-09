// 1-7. 블라인드	https://www.acmicpc.net/problem/2799

#include <iostream>
#include <vector>

using namespace std;

int cnts[5] = {0, };

int main() {
  int r, c; 
  cin >> r >> c;
  
  vector<string> v(r * 5 + 1);
  for(int i = 0; i < v.size(); i++) {
    cin >> v[i];
  }

  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      int type = 0;
      for(type = 0; type < 4; type++) {
        if(v[i * 5 + 1 + type][j * 5 + 1] != '*') break;
      }
      cnts[type] += 1;
    }
  }

  for(int i = 0; i < 5; i++) {
    cout << cnts[i] << ' ';
  }

  return 0;
}