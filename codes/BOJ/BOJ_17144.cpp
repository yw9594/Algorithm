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

			if (n_pos.first < 0 || n_pos.first >= N || n_pos.second < 0 || n_pos.second >= M) continue; // ���� �ʰ�

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
		int num_of_spread = 4; // ���� ���� ��
		queue<Pos> q;

		// ��Ʈ�� ��ġ Ȯ��
		for (int k = 0; k < 4; k++) {
			int n_i = c_i + offset[k][0],
				n_j = c_j + offset[k][1];

			if (n_i < 0 || n_i >= N || n_j < 0 || n_j >= M || board[n_i][n_j] == -1) { // ���� �ְų� ����û������ ���
				num_of_spread--;
				continue;
			}
			else  q.push(Pos(n_i, n_j)); // ���� ��ġ ���� 

		}



		// Ȯ��
		int spread_of_dust = board[c_i][c_j] / 5;
		plusminus[c_i][c_j] -= spread_of_dust * num_of_spread; // �߽ɺ� ���� ����
		while (!q.empty()) { // �ֺ� ���� Ȯ��
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
	// �� ��� (������ ����)
	for (int i = conditioner[0].first - 1; i >= 0; i--) circul_path[0].push_back(Pos(i, 0)); // ���� ��
	for (int j = 1; j < M; j++) circul_path[0].push_back(Pos(0, j)); // ���� ��
	for (int i = 1; i <= conditioner[0].first; i++) circul_path[0].push_back(Pos(i, M - 1)); // ������ ��
	for (int j = M - 2; j >= 1; j--) circul_path[0].push_back(Pos(conditioner[0].first, j)); // �߰�

	// �Ʒ� ���
	for (int i = conditioner[1].first + 1; i < N; i++) circul_path[1].push_back(Pos(i, 0));
	for (int j = 1; j < M; j++) circul_path[1].push_back(Pos(N - 1, j));
	for (int i = N - 2; i >= conditioner[1].first; i--) circul_path[1].push_back(Pos(i, M - 1));
	for (int j = M - 2; j >= 1; j--) circul_path[1].push_back(Pos(conditioner[1].first, j));

}

void circulate(vector<vector<int>>& board, vector<Pos>& conditioner, vector<vector<Pos>>& circul_path) {

	for (int k = 0; k < 2; k++) { // 0:�� / 1:�Ʒ� ��ȯ
		int path_len = circul_path[k].size();
		int c_i = conditioner[k].first, c_j = conditioner[k].second;

		for (int p = 0; p < path_len - 1; p++)  // ��ȯ ��θ� ���� ���� �̵�
			board[circul_path[k][p].first][circul_path[k][p].second]
			= board[circul_path[k][p + 1].first][circul_path[k][p + 1].second];

		board[c_i][c_j + 1] = 0; // ��ȭ�� ���� ����
	}

	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M >> T;

	vector<Pos> conditioner; // ����û���� ��ġ : ��/�Ʒ�
	vector<vector<int>> board(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == -1)
				conditioner.push_back(Pos(i, j));
		}
	}

	vector<vector<Pos>> circul_path(2); // ��/�Ʒ� ���� û������ ���� ��ȯ ���
	make_path(conditioner, circul_path);

	while (T--) {
		vector<Pos> dust_pos;

		// �̼����� ��ġ �ľ�, BFS
		BFS(board, dust_pos);

		// Ȯ��
		spread(board, dust_pos);

		// ��ȯ
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