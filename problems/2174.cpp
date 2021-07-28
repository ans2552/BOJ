#include <iostream>
using namespace std;

int A, B;
int N, M;

int dx[4] = { 1,0,-1,0 }; // E S W N
int dy[4] = { 0,-1,0,1 }; // E S W N

struct Robot {
	int x;
	int y;
	int dir;
};
Robot robots[101];
int arr[101][101];

bool isRange(int x, int y) {
	return x > 0 && y > 0 && x <= A && y <= B;
}


int robotMove(int idx, int cnt) {
	int dir = robots[idx].dir;
	int x = robots[idx].x;
	int y = robots[idx].y;
	for (int i = 0; i < cnt; i++) {
		x += dx[dir];
		y += dy[dir];

		if (!isRange(x, y))
			return 0;
		if (arr[y][x] != 0) 
			return arr[y][x];
	}
	arr[robots[idx].y][robots[idx].x] = 0;
	robots[idx].x = x;
	robots[idx].y = y;
	arr[y][x] = idx;
	return -1;
}

int main() {
	cin >> A >> B;
	cin >> N >> M;

	char dir;
	for (int i = 1; i <= N; i++) {
		cin >> robots[i].x >> robots[i].y >> dir;
		if (dir == 'E')
			robots[i].dir = 0;
		else if (dir == 'S')
			robots[i].dir = 1;
		else if (dir == 'W')
			robots[i].dir = 2;
		else if (dir == 'N')
			robots[i].dir = 3;
		arr[robots[i].y][robots[i].x] = i;
	}

	int num, cnt;
	char command;
	for (int i = 1; i <= M; i++) {
		cin >> num >> command >> cnt;

		if (command == 'F') {
			int result = robotMove(num, cnt);
			if (result == -1)
				continue;
			else if (result == 0)
				cout << "Robot " << num << " crashes into the wall\n";
			else
				cout << "Robot " << num << " crashes into robot " << result << '\n';
			return 0;
		}
		else if (command == 'L') {
			cnt %= 4;
			robots[num].dir -= cnt;
			if (robots[num].dir < 0)
				robots[num].dir += 4;
		}
		else if (command == 'R') {
			cnt %= 4;
			robots[num].dir += cnt;
			if (robots[num].dir >= 4)
				robots[num].dir -= 4;
		}
	}
	cout << "OK\n";
}