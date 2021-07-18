// 12-10. ACM 호텔	https://www.acmicpc.net/problem/10250

#include <cstdio>

int main() {
  int T; scanf("%d", &T);

  while(T--) {
    int h, w, n;
    scanf("%d %d %d", &h, &w, &n);

    int r1 = (n - 1) % h + 1;
    int r2 = (n - 1) / h + 1;
    printf("%d%02d\n", r1, r2);
  }
  return 0;
}