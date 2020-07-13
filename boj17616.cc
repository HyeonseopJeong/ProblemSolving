#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

typedef struct element {
	int n;
	struct element * next;
} element;

element adj_list1[100001];
element adj_list2[100001];
int vis[100001];

void push1(int from, int to) {
	element * e = new element;
	e->n = to;
	e->next = adj_list1[from].next;

	adj_list1[from].next = e;
}

void push2(int from, int to) {
	element * e = new element;
	e->n = to;
	e->next = adj_list2[from].next;

	adj_list2[from].next = e;
}

int dfs1(int n) {
	int ret = 0;
	vis[n] = 1;
	element * cur = adj_list1[n].next;
	while (cur) {
		if (!vis[cur->n]) {
			ret += dfs1(cur->n) + 1;
		}
		cur = cur->next;
	}
	return ret;
}

int dfs2(int n) {
	int ret = 0;
	vis[n] = 1;
	element * cur = adj_list2[n].next;
	while (cur) {
		if (!vis[cur->n]) {
			ret += dfs2(cur->n) + 1;
		}
		cur = cur->next;
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n, m, x;
	
	cin >> n >> m >> x;
	while (m--) {
		int a, b;
		cin >> a >> b;
		
		push1(a, b); //내 뒤에 몇 명인지 구하기.
		push2(b, a); //내 앞에 몇 명인지 구하기.
	}

	int back = dfs1(x);
	
	memset(vis, 0, sizeof(vis));
	
	int front = dfs2(x);

	cout << min(n - back, front + 1) << ' ' << max(n - back, front + 1);

	return 0;
}