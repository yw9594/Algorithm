// 시간 초과  Hint : DFS 형태로 사다리를 놓을 것
/*
#include <iostream>
#include <vector>

using namespace std;

int N, M, H, answer=-1;

int Go(vector<vector<int>>& ladder) {
	int flag = true;
	for (int man = 1; man <= N && flag; man++){
		int c_i = 1, c_j = man;

		while (1) { // 사다리 타기 시작
			if (ladder[c_i][c_j - 1]) { // 왼쪽 이동
				c_j--;
			}
			else if (ladder[c_i][c_j]) { // 오른쪽 이동
				c_j++;
			}
			c_i++; // 아래로 이동

			if (c_i > H) {
				if (c_j != man) flag = false;
				break;
			}
		}
	}
	return flag;
}

int DFS(vector<vector<int>> & ladder, int start_row, int added_ladder,  int max_ladder) {
	int flag = false;
	if (added_ladder == max_ladder) {
		flag = Go(ladder);
		return flag;
	}
	else {
		for (int i = start_row; i <= H; i++) {
			for (int j = 1; j < N; j++) { // 마지막 세로줄은 다리를 만들지 않음
				if (ladder[i][j] == 0) { // 사다리가 없는 경우
					if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue; // 옆에 다리가 이미 있는 경우 패스

					ladder[i][j] = 1;
					flag = DFS(ladder, start_row, added_ladder + 1, max_ladder);
					ladder[i][j] = 0;

					if (flag) return flag;
				}
			}
		}
	}
	return flag;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> H;
	vector<vector<int>> ladder(H+2, vector<int>(N+2, 0)); // i:가로, j: 세로, checked를 간편화하기 위해 오버사이즈
	while (M--) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1; // [a / b:b+1] 연결
	}

	// DFS로 사다리 추가
	for (int max_ladder = 0; max_ladder <= 3; max_ladder++) {
		int flag = DFS(ladder,1, 0, max_ladder);
		if (flag) {
			answer = max_ladder;
			break;
		}
	}
	cout << answer << "\n";
	return 0;
}*/