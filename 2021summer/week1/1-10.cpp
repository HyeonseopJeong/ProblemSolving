#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dict[128] = {0, };

int main() {
  int n; cin >> n;

  while(n--) {
    string s; cin >> s;
    dict[s[0]]++;
  }

  int cnt = 0;
  for(int i = 'a'; i <= 'z'; i++) {
    if(dict[i] >= 5) {
      cout << (char)i;
      cnt++;
    }
  }

  if(!cnt)
    cout << "PREDAJA";
  return 0; 
}