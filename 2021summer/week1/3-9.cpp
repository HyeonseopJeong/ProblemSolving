// 3-9. 아기 석환 뚜루루 뚜루	https://www.acmicpc.net/problem/15947

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;


int main() {
  int n; cin >> n;
  int rem = (n - 1) % 14;
  int quot = (n - 1) / 14;
  int k;

  switch(rem) {
    case 0:
    case 12:
      printf("baby");
      break;
    case 1:
    case 13:
      printf("sukhwan");
      break;
    case 4:
      printf("very");
      break;
    case 5:
      printf("cute");
      break;
    case 8:
      printf("in");
      break;
    case 9:
      printf("bed");
      break;

    case 2:
    case 6:
    case 10:
      k = quot + 2;
      printf("tu");
      if(k >= 5) printf("+ru*%d", k);
      else while(k--) printf("ru");
      printf("\n");
      break;

    case 3:
    case 7:
    case 11:
      k = quot + 1;
      printf("tu");
      if(k >= 5) printf("+ru*%d", k);
      else while(k--) printf("ru");
      printf("\n");
      break;
  }
  return 0;
}