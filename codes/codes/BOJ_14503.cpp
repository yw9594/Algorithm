/*#include <iostream>
#include <vector>

#define UNCLEARED 0
#define WALL 1
#define CLEARED 2

using namespace std;

int N, M;
long long int answer = 0LL;
vector<pair<int, int>> dir(4); // dir[i] ������ ��, ���� ĭ���� �̵��ϱ� ���� offset


void clean(vector<vector<int>>& board, int r, int c, int d) {
    // ��ƾ ����
    int cnt = 0; // ���� üũ

    while (1) {
        int next_d, next_r, next_c;

        // ���� ��ġ û��
        if (board[r][c] == UNCLEARED) {
            board[r][c] = CLEARED;
            answer++;
        }

        // �� ������ ��� üũ ���� ���
        if (cnt == 4) {
            next_r = r - dir[d].first;
            next_c = c - dir[d].second;

            if (board[next_r][next_c] == WALL) break; // ���� �Ұ�
            else {
                cnt = 0;
                r = next_r;
                c = next_c;
                continue;
            }
        }

        // ���� ����
        next_d = ((d - 1) + 4) % 4;      // ���� ����
        next_r = r + dir[next_d].first;
        next_c = c + dir[next_d].second;

        if (board[next_r][next_c] == UNCLEARED) {
            d = next_d;
            r = next_r;
            c = next_c;
            cnt = 0;
            continue;
        }
        else { // ���̰ų� �̹� û�Ұ� �� ���

            d = next_d;
            cnt++;
            continue;
        }
    }
    return;
}

int main(void) {
    freopen("input.txt", "r", stdin);
    std::istream::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int r, c, d;
    vector<vector<int>> board(N);
    for (auto& p : board) p = vector<int>(M);

    cin >> r >> c >> d;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    // �ٶ󺸴� ���� ���� ����
    dir[0] = pair<int, int>(-1, 0); // ��
    dir[1] = pair<int, int>(0, 1);  // ��
    dir[2] = pair<int, int>(1, 0);  // ��
    dir[3] = pair<int, int>(0, -1); // ��

    clean(board, r, c, d);
    cout << answer;

    return 0;
}*/