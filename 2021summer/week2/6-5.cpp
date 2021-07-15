// 6-5. 중복 빼고 정렬하기	https://www.acmicpc.net/problem/10867

#include <iostream>

using namespace std;

int mem[2001] = {0, };

int main() {
  int n;
  cin >> n;

  while(n--) {
    int i; cin >> i;
    mem[i + 1000] = 1;
  } 
  
  for(int i = 0; i <= 2000; i++)
    if(mem[i]) cout << i - 1000 << ' ';

  return 0;
}