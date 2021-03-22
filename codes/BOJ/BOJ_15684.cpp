// �ð� �ʰ�  Hint : DFS ���·� ��ٸ��� ���� ��
/*
#include <iostream>
#include <vector>

using namespace std;

int N, M, H, answer=-1;

int Go(vector<vector<int>>& ladder) {
	int flag = true;
	for (int man = 1; man <= N && flag; man++){
		int c_i = 1, c_j = man;

		while (1) { // ��ٸ� Ÿ�� ����
			if (ladder[c_i][c_j - 1]) { // ���� �̵�
				c_j--;
			}
			else if (ladder[c_i][c_j]) { // ������ �̵�
				c_j++;
			}
			c_i++; // �Ʒ��� �̵�

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
			for (int j = 1; j < N; j++) { // ������ �������� �ٸ��� ������ ����
				if (ladder[i][j] == 0) { // ��ٸ��� ���� ���
					if (ladder[i][j - 1] || ladder[i][j] || ladder[i][j + 1]) continue; // ���� �ٸ��� �̹� �ִ� ��� �н�

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
	vector<vector<int>> ladder(H+2, vector<int>(N+2, 0)); // i:����, j: ����, checked�� ����ȭ�ϱ� ���� ����������
	while (M--) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = 1; // [a / b:b+1] ����
	}

	// DFS�� ��ٸ� �߰�
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