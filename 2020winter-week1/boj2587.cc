#include <bits/stdc++.h>

using namespace std;

vector<int> v(5);

void bubble_sort(vector<int> & v) {
    int len = v.size();
    for(int i = 1; i < len; i++) {
        for(int j = 0; j < len - i; j++) {
            if(v[j] > v[j + 1])
                swap(v[j], v[j + 1]);
        }
    }
}


int main() {
    for(int i = 0; i < 5; i++)
        cin >> v[i];
    
    bubble_sort(v);

    int sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum += v[i];
    
    cout << sum / 5 << '\n' << v[2];
}