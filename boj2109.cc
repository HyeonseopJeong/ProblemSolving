//O(n^2)
#include <bits/stdc++.h>

using namespace std;

struct task {
	int money;
	int duedate;

	bool operator<(const task & t) {
		return money < t.money;
	}
};

int d[10001];
vector<task> v;

int main() {
	int n;
	scanf("%d", &n);

	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].money, &v[i].duedate);

	sort(v.rbegin(), v.rend());

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int day = v[i].duedate;
		while (d[day] && day != 0)
			day -= 1;

		if (day != 0) {
			d[day] = 1;
			ans += v[i].money;
		}
	}

	printf("%d", ans);

	return 0;
}