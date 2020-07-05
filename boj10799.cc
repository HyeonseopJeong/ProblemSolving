#include <iostream>
#include <string>

using namespace std;

int main() {
	string p;
	cin >> p;
	
	int count = 0, depth = 0;

	for (int i = 0; i < p.length(); i++) {
		if (p[i] == '(') depth += 1;
		else {
			depth -= 1;
			if (p[i - 1] == '(')
				count += depth;
			else 
				count += 1;
		}
	}
	cout << count;
	return 0;
}