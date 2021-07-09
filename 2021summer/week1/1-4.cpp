// 1-4. 평균은 넘겠지	https://www.acmicpc.net/problem/4344

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
  int tc; cin >> tc;

  while(tc--) {
    int n; cin >> n;
    
    vector<int> scores(n);
    int sum = 0;

    for(int i = 0; i < n; i++) {
      cin >> scores[i]; 
      sum += scores[i];
    }

    double avg = (double)sum / n;

    int numOfHighers = 0;
    for(int i = 0; i < n; i++) {
      if(avg < (double)scores[i])
        numOfHighers += 1;
    }

    printf("%0.3f%%\n", ((double)numOfHighers / n) * 100);
  }  

  return 0;
}