// 1245 균형점

#include <iostream>
#include <cstdio>

using namespace std;

int x[10], m[10];

double get_str(double point, int n) {
    double ret = 0;
    for(int i = 0; i < n; i++) {
        if(x[i] < point) 
            ret -= m[i] / ((point - x[i]) * (point - x[i]));
        else
            ret += m[i] / ((point - x[i]) * (point - x[i]));
    }
    return ret;
}


int main() {
    int T;  cin >> T;

    for(int tc = 1; tc <= T; ++tc) {
        int n; cin >> n;
        for(int i = 0; i < n; i++)  cin >> x[i];
        for(int i = 0; i < n; i++)  cin >> m[i];
        
        printf("#%d ", tc);
        
        for(int i = 0; i < n - 1; i++) {
            double len = (x[i + 1] - x[i]) / 2.0;
            double point = x[i] + len;

            for(int k = 0; k < 100; k++) {
                double str = get_str(point, n);
                if(str == 0)
                    break;
                else if(str > 0) 
                    point -= len / 2.0;
                else 
                    point += len / 2.0;
                len /= 2.0;
            }

            printf("%0.10lf ", point);
        }
        printf("\n");
    }

}