#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

typedef struct ball {
	int idx, color, size;

	bool operator<(const struct ball & x) {
		return size < x.size;
	}
} ball;

using namespace std;

int n, all, result[200000], counts[200000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<ball> balls;
	stack<ball> st;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int c, s;
		cin >> c >> s;
		balls.push_back({ i, c - 1, s });
	}

	sort(balls.begin(), balls.end());
	
	int prev = -1;

	for (int i = 0; i < balls.size(); i++) {
		if (prev != balls[i].size) {
			while (!st.empty()) {
				ball b = st.top(); st.pop();
				counts[b.color] += b.size;
				all += b.size;
			}
		}
		result[balls[i].idx] = all - counts[balls[i].color];
		
		st.push(balls[i]);
		prev = balls[i].size;
	}

	for (int i = 0; i < n; i++) cout << result[i] << '\n';

	return 0;
}