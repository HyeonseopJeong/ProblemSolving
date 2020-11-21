#include <bits/stdc++.h>

using namespace std;

int ans;
int n, m, set_id ;
vector<string> mmap;

int check[1000][1000];

int main() {
	cin >> n >> m;
	ans = n * m;

	mmap.resize(n);

	for (int i = 0; i < n; i++)
		cin >> mmap[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			set_id += 1;
			int cur_i = i, cur_j = j;

			while (!check[cur_i][cur_j]) {
				check[cur_i][cur_j] = set_id;
				char op = mmap[cur_i][cur_j];

				if(op == 'U')
					cur_i -= 1;
				else if(op == 'D')
					cur_i += 1;
				else if(op == 'L')
					cur_j -= 1;
				else
					cur_j += 1;

				if(check[cur_i][cur_j] != set_id)
					ans -= 1;
			}
		}
	}

	cout << ans;

	return 0;
}