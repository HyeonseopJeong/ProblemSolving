// 1-1. 음계 판별하기	https://www.acmicpc.net/problem/2920

#include <iostream>
#include <string>

using namespace std;

const int LEN = 8;

bool isAscending(int arr[]) {
  for(int i = 0; i < LEN; i++) {
    if(arr[i] != i + 1)
      return false;
  }
  return true;
}

bool isDescending(int arr[]) {
  for(int i = 0; i < LEN; i++) {
    if(arr[i] != LEN - i)
      return false;
  }
  return true;
}

int main() {
  int arr[LEN];

  for(int i = 0; i < LEN; i++)
    cin >> arr[i];

  if(isAscending(arr)) {
    cout << "ascending";
  } else if(isDescending(arr)) {
    cout << "descending";
  } else {
    cout << "mixed";
  }

  return 0;
}