#include <bits/stdc++.h>

using namespace std;


int n, w;
int arr[1001];
int mem[1001][31];
int no_move[1001];


int f(int idx, int move_times) {
	if (idx <= 0)
		return 0;
	if (move_times == 0)
		return no_move[idx];
	
	if (mem[idx][move_times] != -1)
		return mem[idx][move_times];


	int ret = f(idx, move_times - 1);
	
	if (arr[idx] == move_times % 2 + 1) {
		ret = max(ret, f(idx - 1, move_times) + 1);
		ret = max(ret, f(idx - 1, move_times - 1) + 1);
	}
	else {
		ret = max(ret, f(idx - 1, move_times));
	}

	return mem[idx][move_times] = ret;
}


int main() {
	scanf("%d %d", &n, &w);

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		if (arr[i] == 1)
			sum++;
		no_move[i] = sum;
	}

	memset(mem, -1, sizeof(mem));

	cout << f(n, w);
	return 0;
}