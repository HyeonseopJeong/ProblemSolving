#include <iostream>

using namespace std;

int f(int n) {
	int ret = 0;
	while (n) {
		if (n % 10 == 3 || n % 10 == 6 || n % 10 == 9)
			ret += 1;
		n /= 10;
	}
	return ret;
}

int main() {
	int n, ans = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
		ans += f(i);
	cout << ans;

	return 0;
}