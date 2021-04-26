#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int f(int n) {
	return n > 0;
}

int main() {
	int n;
	string str;
	cin >> n >> str;

	long long ans = -1;

	//R이 왼쪽으로
	long long k, a;
	k = a = 0;
	//R이 왼쪽으로
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'B') {
			k++;
		}
		else {
			a += f(k);
		}
	}
	ans = a;

	
	a = k = 0;
	//B가 왼쪽으로
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'R') {
			k++;
		}
		else {
			a += f(k);
		}
	}
	ans = min(ans, a);


	a = k = 0;
	//R이 오른쪽으로
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'B') {
			k++;
		}
		else {
			a += f(k);
		}
	}
	ans = min(ans, a);

	a = k = 0;
	//B가 오른쪽으로
	for (int i = str.length() - 1; i >= 0; i--) {
		if (str[i] == 'R') {
			k++;
		}
		else {
			a += f(k);
		}
	}
	ans = min(ans, a);

	cout << ans;
	return 0;
}