// 3-2. 열개씩 끊어 출력하기	https://www.acmicpc.net/problem/11721

#include <cstdio>
#include <cstring>

using namespace std;

char str[1001];

int main() {
  scanf("%s", str);

  for(int i = 0; i < strlen(str); i+=10) {
    printf("%.10s\n", &str[i]);
  }
  return 0;
}