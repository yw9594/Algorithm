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

int offset[4][2]{ // ���� ���������� �� ������ ���ư��� ����
	0, 1,
	1, 0,
	0, -1,
	-1, 0
};

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N, K, D; // �� ũ�� / ��� ����
	cin >> N >> K;
	vector<vector<int>> board(N + 1); // 1���� �����Կ� ����
	for (auto& b : board) b = vector<int>(N + 1);

	// ��� ǥ��
	for (int k = 0; k < K; k++) {
		int i, j;
		cin >> i >> j;
		board[i][j] = APPLE;
	}
	// ���� ����
	cin >> D;
	map<int, char> chage_dir;
	for (int d = 0; d < D; d++) {
		int i;
		char dir;
		cin >> i >> dir;
		chage_dir[i] = dir;
	}



	// ��ƾ ����
	int answer = 0;
	int cur_dir = 0; // 0123 : ��������
	deque<int_pair_t> snake;
	snake.push_back(pair<int, int>(1, 1));
	board[1][1] = SNAKE;


	while (1) {
		int_pair_t head = snake.front();						// �� �Ӹ� ��ġ 
		int_pair_t next_pos(head.first + offset[cur_dir][0],		// ���� �Ӹ� ��ġ
			head.second + offset[cur_dir][1]);

		answer++; // �ð� �帧

		if (next_pos.first<1 || next_pos.first>N || // �� �Ǵ� �� �� ħ��
			next_pos.second<1 || next_pos.second>N) // �� �Ǵ� �� �� ħ��
			break; // ����

		int next_tile = board[next_pos.first][next_pos.second]; // ���� Ÿ�Ͽ� �����ϴ� ��ü��

		if (next_tile == SNAKE) // ���� ����
			break; // ����

		if (next_tile == APPLE) { // ����� �ִ� ��� ���� �ø�
			snake.push_front(next_pos);
			board[next_pos.first][next_pos.second] = SNAKE;
		}
		else {
			// �Ӹ� �߰�
			snake.push_front(next_pos);
			board[next_pos.first][next_pos.second] = SNAKE;

			// ��������
			int_pair_t tail_pos = snake.back();
			snake.pop_back();
			board[tail_pos.first][tail_pos.second] = TILE;
		}



		// ���� ��ȯ
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