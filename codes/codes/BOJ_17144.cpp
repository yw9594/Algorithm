/*#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> Pos;

int N, M, T;
int offset[4][2] = {
	-1, 0,
	1, 0,
	0, -1,
	0, 1
};

void BFS(vector<vector<int>>& board, vector<Pos>& dust_pos) {
	queue<Pos> q;
	vector<vector<int>> pushed(N, vector<int>(M, 0));

	q.push(Pos(0, 0));
	pushed[0][0] = 1;


	while (!q.empty()) {
		Pos cur_pos = q.front();
		q.pop();

		if (board[cur_pos.first][cur_pos.second] > 0) dust_pos.push_back(cur_pos);

		for (int k = 0; k < 4; k++) {
			Pos n_pos = Pos(cur_pos.first + offset[k][0], cur_pos.second + offset[k][1]);

			if (n_pos.first < 0 || n_pos.first >= N || n_pos.second < 0 || n_pos.second >= M) continue; // 범위 초과

			if (!pushed[n_pos.first][n_pos.second] && board[n_pos.first][n_pos.second] != -1) {
				q.push(n_pos);
				pushed[n_pos.first][n_pos.second] = 1;
			}
		}
	}

	return;
}

void spread(vector<vector<int>>& board, vector<Pos>& dust_pos) {
	vector<vector<int>> plusminus(N, vector<int>(M, 0));

	for (auto& dust : dust_pos) {
		int c_i = dust.first, c_j = dust.second;
		int num_of_spread = 4; // 퍼진 방향 수
		queue<Pos> q;

		// 퍼트릴 위치 확인
		for (int k = 0; k < 4; k++) {
			int n_i = c_i + offset[k][0],
				n_j = c_j + offset[k][1];

			if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M || board[n_i][n_j] == -1) { // 벽이 있거나 공기청정기인 경우
				num_of_spread--;
				continue;
			}
			else  q.push(Pos(n_i, n_j)); // 퍼질 위치 저장 

		}



		// 확산
		int spread_of_dust = board[c_i][c_j] / 5;
		plusminus[c_i][c_j] -= spread_of_dust * num_of_spread; // 중심부 먼지 감소
		while (!q.empty()) { // 주변 먼지 확산
			Pos pos = q.front();
			q.pop();

			plusminus[pos.first][pos.second] += spread_of_dust;
		}
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			board[i][j] += plusminus[i][j];

	return;
}

void make_path(vector<Pos>& conditioner, vector<vector<Pos>>& circul_path) {
	// 위 경로 (역방향 저장)
	for (int i = conditioner[0].first - 1; i >= 0; i--) circul_path[0].push_back(Pos(i, 0)); // 왼쪽 벽
	for (int j = 1; j < M; j++) circul_path[0].push_back(Pos(0, j)); // 윗쪽 벽
	for (int i = 1; i <= conditioner[0].first; i++) circul_path[0].push_back(Pos(i, M - 1)); // 오른쪽 벽
	for (int j = M - 2; j >= 1; j--) circul_path[0].push_back(Pos(conditioner[0].first, j)); // 중간

	// 아래 경로
	for (int i = conditioner[1].first + 1; i < N; i++) circul_path[1].push_back(Pos(i, 0));
	for (int j = 1; j < M; j++) circul_path[1].push_back(Pos(N - 1, j));
	for (int i = N - 2; i >= conditioner[1].first; i--) circul_path[1].push_back(Pos(i, M - 1));
	for (int j = M - 2; j >= 1; j--) circul_path[1].push_back(Pos(conditioner[1].first, j));

}

void circulate(vector<vector<int>>& board, vector<Pos>& conditioner, vector<vector<Pos>>& circul_path) {

	for (int k = 0; k < 2; k++) { // 0:위 / 1:아래 순환
		int path_len = circul_path[k].size();
		int c_i = conditioner[k].first, c_j = conditioner[k].second;

		for (int p = 0; p < path_len - 1; p++)  // 순환 경로를 따라 먼지 이동
			board[circul_path[k][p].first][circul_path[k][p].second]
			= board[circul_path[k][p + 1].first][circul_path[k][p + 1].second];

		board[c_i][c_j + 1] = 0; // 정화된 공기 주입
	}

	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;

	vector<Pos> conditioner; // 공기청정기 위치 : 위/아래
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)
				conditioner.push_back(Pos(i, j));
		}
	}

	vector<vector<Pos>> circul_path(2); // 위/아래 공기 청정기의 공기 순환 경로
	make_path(conditioner, circul_path);

	while (T--) {
		vector<Pos> dust_pos;

		// 미세먼지 위치 파악, BFS
		BFS(board, dust_pos);

		// 확산
		spread(board, dust_pos);

		// 순환
		circulate(board, conditioner, circul_path);

	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (board[i][j] > 0)
				answer += board[i][j];
		}
	}
	cout << answer << "\n";

	return 0;
}*/