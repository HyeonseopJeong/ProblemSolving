//미완!!
//1092 배 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> crains;
vector<int> loads;

int num = 0;
int nCrain[50];
int nLoads[50];


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n;   crains.resize(n);
    for(int i = 0; i < n; i++)
        cin >> crains[i];
    
    cin >> m;   loads.resize(m);
    for(int i = 0; i < m; i++)
        cin >> loads[i];
    
    sort(crains.rbegin(), crains.rend());
    sort(loads.rbegin(), loads.rend());

    if(crains[0] < loads[0]) {
        cout << -1;
        return 0;
    }
    
    for(int i = 0; i < n; i++) {
        if(i != 0 && crains[i - 1] != crains[i])
            num++;
        nCrain[num]++;
    }
    num++;
    crains.erase(unique(crains.begin(), crains.end()), crains.end());

    int idx = 0;
    for(int i = 0; i < num; i++) {
        if(i == num - 1) {
            for( ; idx < loads.size(); idx++)
                nLoads[i]++;
        }
        else {
            for( ; idx < loads.size() && crains[i + 1] < loads[idx]; idx++)
                nLoads[i]++;
        }
    }

    
    int ans = 0;

    for(int i = 0; i < num; i++) {
        if(nLoads[i] > 0) {
            int time = 1 + (nLoads[i] - 1) / nCrain[i]; //양수 나누기 ceiling 스킬
            ans += time;
            int remain = 0;
            for(int j = i; j < num; j++) {
                nLoads[j] -= (time * nCrain[j] + remain);
                if(nLoads[j] < 0) {
                    remain = -nLoads[j];
                    nLoads[j] = 0;
                }
            }
        }

        nCrain[i + 1] += nCrain[i];
    }

    cout << ans;

    return 0;
}