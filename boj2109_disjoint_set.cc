//disjoint set을 이용하여 시간복잡도를 줄임.
// O(n)

#include <bits/stdc++.h>

using namespace std;

int p[10001];

int find(int a) {
	if (p[a] == a)
		return a;
	return p[a] = find(p[a]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a < b)
		p[b] = a;
	else
		p[a] = b;
}


struct task {
	int money;
	int duedate;

	bool operator<(const task & t) {
		return money < t.money;
	}
};

vector<task> v;

int main() {
	int n;
	scanf("%d", &n);

	v.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &v[i].money, &v[i].duedate);

	sort(v.rbegin(), v.rend());

	for (int i = 0; i <= 10000; i++)
		p[i] = i;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		int day = find(v[i].duedate);

		if (day != 0) {
			ans += v[i].money;
			merge(day, day - 1);
		}
	}

	printf("%d", ans);

	return 0;
}