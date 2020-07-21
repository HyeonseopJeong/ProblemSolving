#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
vector<int> v, a_v, b_v;
vector<char> s;

long long a, b;

void f(int idx, int dep) {
	if (dep == k + 1) {
		vector<int> perm = v;
		do {
			long long num = perm[0];
			int i;

			for (i = 0; i < k; i++) {
				if (s[i] == '<') {
					if (perm[i] >= perm[i + 1])
						break;
				}
				else {
					if (perm[i] <= perm[i + 1])
						break;
				}
				num = num * 10 + perm[i + 1];
			}


			if (i == k) {
				if (a == 0) {
					a = b = num;
					a_v = b_v = perm;
				}
				else {
					if (a < num) {
						a = num;
						a_v = perm;
					}
					if (b > num) {
						b = num;
						b_v = perm;
					}
				}
			}
		} while (next_permutation(perm.begin(), perm.end()));

		return;
	}


	for (int i = idx + 1; i < 10; i++) {
		v.push_back(i);
		f(i, dep + 1);
		v.pop_back();
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> k;
	s.resize(k);
	for(int i = 0; i < k; i++)
		cin >> s[i];

	
	f(-1, 0);

	for (int i = 0; i < a_v.size(); i++)
		cout << a_v[i];
	cout << '\n';

	for (int i = 0; i < b_v.size(); i++)
		cout << b_v[i];

	return 0;
}