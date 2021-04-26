#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[9];
int done = 0;
vector<int> result;

void f(int idx) {
    if(done)
        return;
    if(result.size() == 7) {
        int sum = 0;
        for(int i = 0; i < 7; i++)
            sum += result[i];

        if(sum == 100) {
            for(int i = 0; i < 7; i++)
                cout << result[i] << '\n';
            done = 1;
        }
        return;
    }
    if(idx >= 9)
        return;
    
    result.push_back(arr[idx]);
    f(idx + 1);
    result.pop_back();
    f(idx + 1);
    return;
}


int main() {
    
    for(int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 9);
    
    f(0);


    return 0;
}