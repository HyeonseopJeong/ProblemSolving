#include <bits/stdc++.h>

using namespace std;

const int INF = 3000001;

vector<pair<int ,int>> graph[20001];
int dist[20001];
bool visited[20001];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


int main() {
	int n, m, start;
	scanf("%d %d %d", &n, &m, &start);

	for (int i = 0; i < m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		graph[u].push_back({ w, v });
	}


	for (int i = 1; i <= n; i++)
		dist[i] = INF;
	dist[start] = 0;

	pq.push({ 0, start });

	while (!pq.empty()) {
		while (!pq.empty() && visited[pq.top().second])
			pq.pop();
		if (pq.empty())
			break;

		pair<int, int> cur = pq.top();	pq.pop(); visited[cur.second] = 1;

		for (pair<int, int> next : graph[cur.second]) {
			if (dist[next.second] > dist[cur.second] + next.first) {
				dist[next.second] = dist[cur.second] + next.first;
				pq.push({ dist[next.second], next.second });
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}