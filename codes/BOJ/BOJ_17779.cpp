/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

typedef pair<int, int> Pos;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>> board(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> board[i][j];

	int answer = 210000000;

	// ����
	for (int d1 = 1; d1 <= N; d1++) {
		for (int d2 = 1; d2 <= N; d2++) {
			for (int x = 1; x <= N; x++) {
				for (int y = 1; y <= N; y++) {
					if ((x + d1 + d2) <= N && (1 <= (y - d1)) && ((y + d2) <= N)) {
						vector<vector<int>> area(N + 1, vector<int>(N + 1, 0));


						// 5�� ���� ��輱 ����
						for (int i = 0; i <= d1; i++) area[x + i][y - i] = 5;
						for (int i = 0; i <= d2; i++) area[x + i][y + i] = 5;
						for (int i = 0; i <= d2; i++) area[x + d1 + i][y - d1 + i] = 5;
						for (int i = 0; i <= d1; i++) area[x + d2 + i][y + d2 - i] = 5;

						// 5�� ���� ä���ֱ�
						for (int i = x + 1; i < x + d1 + d2; i++) {
							int flag = 0;
							for (int j = y - d1; j <= y + d2; j++) {
								if (area[i][j] == 5 && flag == 0) { // 5�� ���� ��ŸƮ
									flag = 1;
								}
								else if (area[i][j] == 5 && flag == 1) { // 5�� ���� ���� 
									break;
								}
								else if (flag) { // 5�� ä�� ����
									area[i][j] = 5;
								}
								else continue;

							}
						}

						// ������ ���� ä���ֱ� 
						for (int i = 1; i <= N; i++) {
							for (int j = 1; j <= N; j++) {
								if (area[i][j] == 5) continue;
								if (1 <= i && i < x + d1 && 1 <= j && j <= y) area[i][j] = 1;
								else if (1 <= i && i <= x + d2 && y <= j && j <= N) area[i][j] = 2;
								else if (x + d1 <= i && i <= N + d1 && 1 <= j && j < y - d1 + d2) area[i][j] = 3;
								else if (x + d2 < i && i <= N && y - d1 + d2 <= j && j <= N) area[i][j] = 4;
							}
						}

						//show_line();
						// show_2d_array(area);
						// �α��� ���ϱ�
						vector<int> pops(5, 0);
						for (int i = 1; i <= N; i++)
							for (int j = 1; j <= N; j++)
								pops[area[i][j] - 1] += board[i][j];
						sort(pops.begin(), pops.end());

						int temp = pops[4] - pops[0];
						answer = answer < temp ? answer : temp;

					}
				}
			}
		}
	}

	cout << answer << "\n";

	return 0;
}*/