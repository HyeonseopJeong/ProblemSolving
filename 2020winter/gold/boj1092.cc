//1092 배 


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> crains, boxes;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n;   crains.resize(n);
    for(int i = 0; i < n; i++)
        cin >> crains[i];

    cin >> m;   boxes.resize(m);
    for(int i = 0; i < m; i++)
        cin >> boxes[i];
    
    sort(crains.rbegin(), crains.rend());
    sort(boxes.rbegin(), boxes.rend());

    if(crains[0] < boxes[0]) {
        cout << -1;
        return 0;
    }

    int ans = 0;
    while(m) {
        for(int i = 0; i < crains.size(); i++) {
            int check = 0;
            for(int j = 0; j < boxes.size(); j++) {
                if(boxes[j] != -1 && boxes[j] <= crains[i]) {
                    m--; check = 1;
                    boxes[j] = -1;
                    break;
                }
            }
            if(!check)
                crains.erase(crains.begin() + i, crains.end());
        }
        ans++;
    }

    cout << ans;

    return 0;
}