/*#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <deque>

#define TILE  0
#define SNAKE 1
#define APPLE 2

using namespace std;

typedef pair<int, int> int_pair_t;

int offset[4][2]{ // 각각 동남서북일 때 앞으로 나아가는 방향
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, D; // 맵 크기 / 사과 개수
	cin >> N >> K;
	vector<vector<int>> board(N + 1); // 1부터 시작함에 주의
	for (auto& b : board) b = vector<int>(N + 1);

	// 사과 표현
	for (int k = 0; k < K; k++) {
		int i, j;
		cin >> i >> j;
		board[i][j] = APPLE;
	}
	// 방향 저장
	cin >> D;
	map<int, char> chage_dir;
	for (int d = 0; d < D; d++) {
		int i;
		char dir;
		cin >> i >> dir;
		chage_dir[i] = dir;
	}



	// 루틴 시작
	int answer = 0;
	int cur_dir = 0; // 0123 : 동남서북
	deque<int_pair_t> snake;
	snake.push_back(pair<int, int>(1, 1));
	board[1][1] = SNAKE;


	while (1) {
		int_pair_t head = snake.front();						// 뱀 머리 위치 
		int_pair_t next_pos(head.first + offset[cur_dir][0],		// 다음 머리 위치
			head.second + offset[cur_dir][1]);

		answer++; // 시간 흐름

		if (next_pos.first<1 || next_pos.first>N || // 북 또는 남 벽 침범
			next_pos.second<1 || next_pos.second>N) // 서 또는 동 벽 침범
			break; // 종료

		int next_tile = board[next_pos.first][next_pos.second]; // 다음 타일에 존재하는 물체ㄴ

		if (next_tile == SNAKE) // 몸통 닿음
			break; // 종료

		if (next_tile == APPLE) { // 사과가 있는 경우 길이 늘림
			snake.push_front(next_pos);
			board[next_pos.first][next_pos.second] = SNAKE;
		}
		else {
			// 머리 추가
			snake.push_front(next_pos);
			board[next_pos.first][next_pos.second] = SNAKE;

			// 꼬리제거
			int_pair_t tail_pos = snake.back();
			snake.pop_back();
			board[tail_pos.first][tail_pos.second] = TILE;
		}



		// 방향 전환
		auto change = chage_dir.find(answer);
		if (change != chage_dir.end()) {
			char c = change->second;
			if (c == 'L')
				cur_dir = (cur_dir + 3) % 4;
			else
				cur_dir = (cur_dir + 1) % 4;
		}
	}
	cout << answer << "\n";
	return 0;
}*/