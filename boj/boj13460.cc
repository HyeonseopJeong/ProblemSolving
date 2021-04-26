/*
2020-06-27
#삼성역테기출 #BFS #브루트포스

*/


#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int Br, Bc, Rr, Rc, N, M, Or, Oc;


int visit[4][20][20][20][20];

typedef enum Dir {
	LEFT,
	RIGHT,
	UP,
	DOWN
} Direction;


struct Sit {
	int Br;
	int Bc;
	int Rr;
	int Rc;
	int num;
};

char map[20][20];


int is_done(Sit cur) {
	if (cur.num > 10 || (cur.Br == Or && cur.Bc == Oc)) return -1;
	if (cur.Rr == Or && cur.Rc == Oc) return 1;
	return 0;

}


Sit move(Sit cur, Direction dir) {
	Sit ret = cur;
	ret.num++;
	if (dir == LEFT) {
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br != ret.Rr || ret.Bc - 1 != ret.Rc) && (map[ret.Br][ret.Bc - 1] != '#'))
			ret.Bc -= 1;
		while ((ret.Rr != Or || ret.Rc != Oc) && (ret.Rr != ret.Br || ret.Rc - 1 != ret.Bc) && (map[ret.Rr][ret.Rc - 1] != '#'))
			ret.Rc -= 1;
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br != ret.Rr || ret.Bc - 1 != ret.Rc) && (map[ret.Br][ret.Bc - 1] != '#'))
			ret.Bc -= 1;
		if (ret.Br == Or && ret.Bc - 1 == Oc) ret.Bc--;
	}
	else if (dir == RIGHT) {
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br != ret.Rr || ret.Bc + 1 != ret.Rc) && (map[ret.Br][ret.Bc + 1] != '#'))
			ret.Bc += 1;
		while ((ret.Rr != Or || ret.Rc != Oc) && (ret.Rr != ret.Br || ret.Rc + 1 != ret.Bc) && (map[ret.Rr][ret.Rc + 1] != '#'))
			ret.Rc += 1;
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br != ret.Rr || ret.Bc + 1 != ret.Rc) && (map[ret.Br][ret.Bc + 1] != '#'))
			ret.Bc += 1;
		if (ret.Br == Or && ret.Bc + 1 == Oc) ret.Bc++;
	}
	else if (dir == UP) {
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br - 1 != ret.Rr || ret.Bc != ret.Rc) && (map[ret.Br - 1][ret.Bc] != '#'))
			ret.Br -= 1;
		while ((ret.Rr != Or || ret.Rc != Oc) && (ret.Rr - 1 != ret.Br || ret.Rc != ret.Bc) && (map[ret.Rr - 1][ret.Rc] != '#'))
			ret.Rr -= 1;
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br - 1 != ret.Rr || ret.Bc != ret.Rc) && (map[ret.Br - 1][ret.Bc] != '#'))
			ret.Br -= 1;
		if (ret.Br - 1 == Or && ret.Bc == Oc) ret.Br--;
	}

	//DOWN
	else {
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br + 1 != ret.Rr || ret.Bc != ret.Rc) && (map[ret.Br + 1][ret.Bc] != '#'))
			ret.Br += 1;
		while ((ret.Rr != Or || ret.Rc != Oc) && (ret.Rr + 1 != ret.Br || ret.Rc != ret.Bc) && (map[ret.Rr + 1][ret.Rc] != '#'))
			ret.Rr += 1;
		while ((ret.Br != Or || ret.Bc != Oc) && (ret.Br + 1 != ret.Rr || ret.Bc != ret.Rc) && (map[ret.Br + 1][ret.Bc] != '#'))
			ret.Br += 1;
		if (ret.Br + 1 == Or && ret.Bc == Oc) ret.Br++;
	}

	return ret;
}


int bfs() {
	queue<Sit> qu;
	qu.push({ Br, Bc, Rr, Rc , 0});
	while (!qu.empty()) {
		Sit cur = qu.front();
		qu.pop();
		int check = is_done(cur);
		if (check == -1) {
			continue;
		}
		else if (check == 1) {
			return cur.num;
		}
		
		for (int dir = LEFT; dir < 4; dir++) {
			if (!visit[dir][cur.Br][cur.Bc][cur.Rr][cur.Rc]) {
				visit[dir][cur.Br][cur.Bc][cur.Rr][cur.Rc] = 1;
				qu.push(move(cur, (Direction)dir));
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf(" %c", &map[i][j]);
			if (map[i][j] == 'B') {
				Br = i;
				Bc = j;
			}
			else if (map[i][j] == 'R') {
				Rr = i;
				Rc = j;
			}
			else if (map[i][j] == 'O') {
				Or = i;
				Oc = j;
			}
		}
	}
	
	cout << bfs();

	return 0;
}


/*
5 5
#####
#RO##
#####
#B###
#####

*/