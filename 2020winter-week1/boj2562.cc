#include <bits/stdc++.h>

using namespace std;

int arr[9];

int main() {
    int max_idx = 0;

    for(int i = 0; i < 9; i++)
        cin >> arr[i];
    
    for(int i = 0; i < 9; i++)
        if(arr[max_idx] < arr[i])
            max_idx = i;
    
    cout << arr[max_idx] << '\n' << max_idx + 1;

    return 0;
}