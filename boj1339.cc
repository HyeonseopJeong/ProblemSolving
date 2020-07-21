#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int vis[26];

vector<char> alphas;
vector<int> perm;
vector<string> strs;

long long ans = 0;

long long f(const string & str) {
	long long ret = 0;
	
	for (int i = 0; i < str.length(); i++) {
		for (int j = 0; j < alphas.size(); j++) {
			if (str[i] == alphas[j]) {
				ret = ret * 10 + perm[j];
				break;
			}
		}
	}

	return ret;
}

int main() {
	int n;
	cin >> n;
	strs.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> strs[i];
		for (int j = 0; j < strs[i].length(); j++) {
			char ch = strs[i][j];
			if (!vis[ch - 'A']) {
				alphas.push_back(ch);
				vis[ch - 'A'] = 1;
			}
		}
	}

	sort(alphas.begin(), alphas.end());
	for (int i = 10 - alphas.size(); i < 10; i++) {
		perm.push_back(i);
	}
	
	do {
		long long num = 0;
		for (int i = 0; i < n; i++) {
			num += f(strs[i]);
		}
		ans = max(ans, num);

	} while (next_permutation(perm.begin(), perm.end()));

	cout << ans;
	return 0;
}