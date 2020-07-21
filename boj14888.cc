#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ans1 = -1e9, ans2 = 1e9;

int ops[4];

vector<int> v;

void f(int idx, int result) {
	if (idx == v.size()) {
		ans1 = max(ans1, result);
		ans2 = min(ans2, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (i == 0 && ops[i] != 0) {
			ops[i]--;
			f(idx + 1, result + v[idx]);
			ops[i]++;
		}
		else if (i == 1 && ops[i] != 0) {
			ops[i]--;
			f(idx + 1, result - v[idx]);
			ops[i]++;
		}
		else if (i == 2 && ops[i] != 0) {
			ops[i]--;
			f(idx + 1, result * v[idx]);
			ops[i]++;
		}
		else if(i == 3 && ops[i] != 0){
			ops[i]--;
			f(idx + 1, result / v[idx]);
			ops[i]++;
		}
	}
}

int main() {
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < 4; i++)
		cin >> ops[i];

	f(1, v[0]);
	cout << ans1 << '\n' << ans2;
	return 0;
}