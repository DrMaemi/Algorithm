#include <iostream>
#include <vector>

using namespace std;
struct P {
	P(int _y, int _x) : x(_x), y(_y) { }
	int x, y;
};
bool done = false;
int world[9][9];
vector<P> p;

void dfs(int cnt) {
	if (cnt == p.size()) {
		done = true;
		return;
	}

	P it = p[cnt];
	int y = it.y, x = it.x;
	bool marked[10] = {};
	for (int i = 0; i < 9; i++) {
		marked[world[y][i]] = true;
		marked[world[i][x]] = true;
	}

	int sx, sy, ex, ey;
	sx = (x / 3) * 3;
	sy = (y / 3) * 3;
	ex = sx + 3;
	ey = sy + 3;
	for (int i = sy; i < ey; i++) {
		for (int j = sx; j < ex; j++) {
			marked[world[i][j]] = true;
		}
	}

	for (int i = 1; i <= 9; i++) {
		if (!marked[i]) {
			if(!done) world[y][x] = i;
			if(!done) dfs(cnt + 1);
			if(!done) world[y][x] = 0;
		}
	}
}

int main() {
	for (int i = 0; i < 9; i++) for (int j = 0; j < 9; j++) {
		scanf("%d", &world[i][j]);
		if (world[i][j] == 0) p.push_back(P(i, j));
	}
	dfs(0);
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) printf("%d ", world[i][j]);
		printf("\n");
	}
	return 0;
}