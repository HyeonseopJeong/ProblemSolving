#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int n;
		scanf("%d", &n);
		vector<int> v(n);

		for (int i = 0; i < n; i++)
			scanf("%d", &v[i]);

		sort(v.begin(), v.end());

		int ans = max(v[1] - v[0], v[2] - v[0]);

		for (int i = 1; i + 2 < n; i++)
			ans = max(ans, v[i + 2] - v[i]);
		ans = max(ans, v[n - 1] - v[n - 2]);

		printf("%d\n", ans);
	}
	return 0;
}