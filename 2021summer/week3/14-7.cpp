#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
  if(s1.length() == s2.length())
    return s1 < s2;
  return s1.length() < s2.length();
}

int main() {
  ios::sync_with_stdio(false); cin.tie(0);
  int n; cin >> n;
  vector<string> words(n);

  for(int i = 0; i < n; i++) {
    cin >> words[i];
  }

  sort(words.begin(), words.end(), comp);
  words.erase(unique(words.begin(), words.end()), words.end());
  
  for(int i = 0; i < words.size(); i++) {
    cout << words[i] << '\n';
  }
  return 0;
}
