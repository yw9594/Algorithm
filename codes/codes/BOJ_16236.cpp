/*#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

typedef pair<int, int> Pos;

struct Fish {
	int weight, i, j, time;
	Fish(int weight, int i, int j) {
		this->weight = weight;
		this->i = i;
		this->j = j;
		this->time = time;
	}
	bool operator<(const Fish& arg) {
		return this->weight < arg.weight;
	}

};

struct Elem {
	int i, j, time;
	Elem(int i = -1, int j = -1, int time = -1) {
		this->i = i;
		this->j = j;
		this->time = time;
	}
	bool operator<(const Elem& arg) {
		if (this->time != arg.time) {
			return this->time < arg.time;
		}
		else {
			if (this->i != arg.i) {
				return this->i < arg.i;
			}
			else
				return this->j < arg.j;
		}
	}
};

int N;
int shark_size = 2, shark_exp = 0;
long long int answer = 0LL;
Pos shark_pos;
int offset[4][2] = {
	0,1,
	1, 0,
	0, -1,
	-1, 0
};
vector<vector<int>> board;

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	board.resize(N);
	for (auto& p : board) p = vector<int>(N);

	// 보드 초기화 및 물고기 정보 저장
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 9)
				shark_pos = Pos(i, j);
		}
	}

	// solution
	while (1) {
		vector<vector<int>> pushed(N); for (auto& p : pushed) p = vector<int>(N, 0);
		vector<Elem> eats;
		queue<Elem> q;

		q.push(Elem(shark_pos.first, shark_pos.second, 0));
		pushed[shark_pos.first][shark_pos.second] = 1;

		// 먹킷 리스트 작성
		while (!q.empty()) {
			Elem cur_elem = q.front();
			q.pop();

			if (1 <= board[cur_elem.i][cur_elem.j] && board[cur_elem.i][cur_elem.j] <= 6 && board[cur_elem.i][cur_elem.j] < shark_size) // 먹킷리스트 추가 
				eats.push_back(cur_elem);

			for (int k = 0; k < 4; k++) {
				int next_i = cur_elem.i + offset[k][0],
					next_j = cur_elem.j + offset[k][1];

				if (next_i < 0 || next_i >= N || next_j < 0 || next_j >= N) continue; // 범위 초과시 무시

				if (!pushed[next_i][next_j] && board[next_i][next_j] <= shark_size) { // 아직 검사 안했는데 먹을 수 있는 경우
					q.push(Elem(next_i, next_j, cur_elem.time + 1));
					pushed[next_i][next_j] = 1;
				}
			}
		}

		// 먹을 물고기 선택
		int eats_num = eats.size();
		Elem dinner;

		if (eats_num == 0) break; // 먹을 수 있는 물고기가 없는 경우


		sort(eats.begin(), eats.end()); // 먹을 물고기 선택 


		dinner = Elem(eats[0].i, eats[0].j, eats[0].time);

		// 식사
		board[shark_pos.first][shark_pos.second] = 0;
		board[dinner.i][dinner.j] = 9;


		shark_pos.first = dinner.i;
		shark_pos.second = dinner.j;

		shark_exp += 1; // 경험치 증가 
		if (shark_exp == shark_size) {
			shark_exp = 0;
			shark_size++;
		}
		answer += (long long int)dinner.time;
	}

	cout << answer << "\n";

	return 0;
}*/