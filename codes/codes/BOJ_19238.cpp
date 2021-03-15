/* ���̺귯�� & �޼ҵ�
// Headers
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

// input
std::istream>::sync_with_stdio(false);
cin.tie(NULL);
*/
/*
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define MAX 99999999

struct Pos {
	int i, j; // ���� ��ġ
	int d;    // ���������κ��� �Ÿ�
};

struct Taxi {
	int i, j; // ���� ��ġ
	int f;    // ����
};

struct Tile {
	int type;		// 0, 1, 2 : �����, ��, �մ�
	int client_no;  // �մ��� ��� �մ� ��ȣ
	int dest_i, dest_j;     // �մ��� ��� ������
};

int N, M, F;
int ans = 0;
vector<vector<Tile>> board;

int offset[4][2] = {
	-1,0,
	1, 0,
	0, -1,
	0, 1
};

inline bool check(Pos& next_pos, Pos& next_client_pos) {
	if (next_pos.i<1 || next_pos.i>N || next_pos.j<1 || next_pos.j>N) return false;
	if (next_pos.d > next_client_pos.d) return false; // �̹� ã�� �ִ� �մԺ��� �Ÿ��� Ŭ ���, ���ʿ�
	return true;
}

inline bool check(Pos& next_pos) {
	if (next_pos.i<1 || next_pos.i>N || next_pos.j<1 || next_pos.j>N) return false;
	return true;
}

bool move(Taxi& taxi) {

	// �ּ� �Ÿ� �մ� ã��
	queue<Pos> q;
	vector<vector<int>> pushed(N + 1, vector<int>(N + 1, 0));

	q.push({ taxi.i, taxi.j, 0 });
	pushed[taxi.i][taxi.j] = 1;

	Pos next_client_pos = { -1, -1, MAX }; // ���� �մ��� ��ġ ����
	while (!q.empty()) {
		Pos cur_pos = q.front();
		q.pop();

		//cout << cur_pos.i << " " << cur_pos.j << " " << cur_pos.d << "-\n";


		if (board[cur_pos.i][cur_pos.j].type == 2) {
			if (cur_pos.d == next_client_pos.d) {		// �Ÿ��� ���� ���, ��� ���� �� ���� ��
				if (cur_pos.i == next_client_pos.i)
					next_client_pos = (cur_pos.j < next_client_pos.j) ? cur_pos : next_client_pos;
				else
					next_client_pos = (cur_pos.i < next_client_pos.i) ? cur_pos : next_client_pos;
			}
			else if (cur_pos.d > next_client_pos.d) // �ִ� �Ÿ��� �ƴϹǷ� ����
				break;
			else // BFS�� �ִ� �Ÿ� ������ �湮�ϹǷ� �׳� ����
				next_client_pos = cur_pos;
		}

		for (int k = 0; k < 4; k++) {
			Pos next_pos = { cur_pos.i + offset[k][0],
							 cur_pos.j + offset[k][1],
							 cur_pos.d + 1 };

			if (check(next_pos, next_client_pos) &&  // ��� �� d �˻�
				board[next_pos.i][next_pos.j].type != 1 &&  // �� �˻�
				!pushed[next_pos.i][next_pos.j]) {          // Ǫ�� ���� �˻�


				q.push(next_pos);
				pushed[next_pos.i][next_pos.j] = 1;
			}
		}
	}
	// ��ȿ�� �˻�
	if (next_client_pos.i == -1 ||	// �մ��� �������� �ʴ� ���
		next_client_pos.d > taxi.f  // �մ��� ã������ ���ᰡ ������ ���
		) return false;



	// �ý�, �մ� ��ġ�� �̵�
	Tile cur_client = board[next_client_pos.i][next_client_pos.j];				// ���� �մ� ��ġ
	board[next_client_pos.i][next_client_pos.j] = { 0, -1, -1, -1 };			// �մ� Tile -> �� ���� Tile
	taxi = { next_client_pos.i, next_client_pos.j, taxi.f - next_client_pos.d };  // �ý� ���� ����



	// �ý�, �մ��� �������� �̵�
	queue<Pos> q2;
	vector<vector<int>> pushed2(N + 1, vector<int>(N + 1, 0));

	q2.push({ taxi.i, taxi.j, 0 });
	pushed2[taxi.i][taxi.j] = 1;

	Pos next_dest_pos = { -1, -1, -1 }; // �Һ�Ǵ� ���ᷮ

	while (!q2.empty()) {
		Pos cur_pos = q2.front();
		q2.pop();

		// cout << cur_pos.i << " " << cur_pos.j << " " << cur_pos.d << "--\n";


		if (cur_pos.i == cur_client.dest_i && cur_pos.j == cur_client.dest_j) {
			next_dest_pos = cur_pos;
			break;
		}

		for (int k = 0; k < 4; k++) {
			Pos next_pos = { cur_pos.i + offset[k][0],
							 cur_pos.j + offset[k][1],
							 cur_pos.d + 1 };

			if (check(next_pos) &&                          // ��� �˻�
				board[next_pos.i][next_pos.j].type != 1 &&  // �� �˻�
				!pushed2[next_pos.i][next_pos.j]) {          // Ǫ�� ���� �˻�
				q2.push(next_pos);
				pushed2[next_pos.i][next_pos.j] = 1;
			}
		}
	}

	// ��ȿ�� �˻�
	if (next_dest_pos.i == -1 ||		// �������� ��ã�� ���
		next_dest_pos.d > taxi.f)		// ���ᰡ ���ڶ�� ���
		return false;

	// �ý� ���� ����
	taxi = { next_dest_pos.i, next_dest_pos.j, taxi.f + next_dest_pos.d }; // �Ҹ��� ������ 2��� ����

	return true;
}

int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է�
	cin >> N >> M >> F;

	board = vector<vector<Tile>>(N + 1, vector<Tile>(N + 1));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int type;
			cin >> type;
			board[i][j] = { type, -1, -1, -1 };
		}
	}

	int start_i, start_j;
	cin >> start_i >> start_j;

	for (int i = 0; i < M; i++) {
		int c_i, c_j, d_i, d_j;
		cin >> c_i >> c_j >> d_i >> d_j;
		board[c_i][c_j] = { 2, i, d_i, d_j }; // �մ� ����
	}

	// ���� �ذ�
	Taxi taxi = { start_i, start_j, F };
	int m = 0;
	for (; m < M; m++) {
		// �ּ� �Ÿ� �°� ã�� �������� �̵��ϱ� 
		int flag = move(taxi); // ���� �� true ��ȯ
		if (!flag)
			break;
	}

	ans = m == M ? taxi.f : -1;

	cout << ans << "\n";

	return 0;
}*/