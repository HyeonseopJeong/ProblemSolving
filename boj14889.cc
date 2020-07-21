#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int ans = 1e9, n;

int table[20][20], vis[20];

void go(int idx, int dep) {
	if (dep == n / 2) {
		int a = 0, b = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (vis[i] && vis[j])
					a += table[i][j];
				if (!vis[i] && !vis[j])
					b += table[i][j];
			}
		}
		ans = min(ans, abs(a - b));
		return;
	}

	for (int i = idx + 1; i < n; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			go(i, dep + 1);
			vis[i] = 0;
		}
	}


}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}
	go(-1, 0);
	cout << ans;
	return 0;
}