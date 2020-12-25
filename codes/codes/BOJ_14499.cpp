/*#include <iostream>
#include <vector>

#define TOP 1
#define BOTTOM 6

using namespace std;

int offset[4][2] = {
	0, 1,  // 동
	0, -1, // 서
	-1, 0, // 북
	1, 0   // 남
};

void roll_dice(vector<int>& dice, int dir) {
	int temp;
	if (dir == 1) { // 동
		temp = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[6];
		dice[6] = temp;
	}
	else if (dir == 2) { // 서
		temp = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[6];
		dice[6] = temp;
	}
	else if (dir == 3) { // 북
		temp = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[6];
		dice[6] = temp;
	}
	else if (dir == 4) { // 남
		temp = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[6];
		dice[6] = temp;
	}
	return;
}

int main(void) {
	int N, M, cur_i, cur_j, K;

	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> cur_i >> cur_j >> K;
	vector<vector<int>> arr(N);
	for (auto& r : arr) r = vector<int>(M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	vector<int> cmd(K);
	for (int i = 0; i < K; i++) cin >> cmd[i];

	// 주사위 : 123456 : 위 상 우 좌 하 아래, 0:더미
	vector<int> dice(7);
	for (int i = 1; i <= 6; i++) dice[i] = 0;

	for (auto& move : cmd) {
		int next_i = cur_i + offset[move - 1][0],
			next_j = cur_j + offset[move - 1][1];

		if (next_i < 0 || next_j < 0 || next_i >= N || next_j >= M) continue; // 범위를 벗어나는 경우

		roll_dice(dice, move); // 주사위 굴리기
		cur_i = next_i; // 이동
		cur_j = next_j;



		if (arr[cur_i][cur_j] != 0) {
			dice[BOTTOM] = arr[cur_i][cur_j];
			arr[cur_i][cur_j] = 0;
		}
		else {
			arr[cur_i][cur_j] = dice[BOTTOM];
		}
		//cout << next_i << " " << next_j << "\n";
		//for (auto& p : dice) cout << p << " ";
		//cout << "\n";
		cout << dice[TOP] << "\n";

	}

	return 0;
}*/