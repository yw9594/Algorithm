/*#include <iostream>
#include <vector>

#define UNCLEARED 0
#define WALL 1
#define CLEARED 2

using namespace std;

int N, M;
long long int answer = 0LL;
vector<pair<int, int>> dir(4); // dir[i] 방향일 때, 앞쪽 칸으로 이동하기 위한 offset


void clean(vector<vector<int>>& board, int r, int c, int d) {
    // 루틴 시작
    int cnt = 0; // 방향 체크

    while (1) {
        int next_d, next_r, next_c;

        // 현재 위치 청소
        if (board[r][c] == UNCLEARED) {
            board[r][c] = CLEARED;
            answer++;
        }

        // 네 방향을 모두 체크 했을 경우
        if (cnt == 4) {
            next_r = r - dir[d].first;
            next_c = c - dir[d].second;

            if (board[next_r][next_c] == WALL) break; // 후진 불가
            else {
                cnt = 0;
                r = next_r;
                c = next_c;
                continue;
            }
        }

        // 다음 방향
        next_d = ((d - 1) + 4) % 4;      // 왼쪽 방향
        next_r = r + dir[next_d].first;
        next_c = c + dir[next_d].second;

        if (board[next_r][next_c] == UNCLEARED) {
            d = next_d;
            r = next_r;
            c = next_c;
            cnt = 0;
            continue;
        }
        else { // 벽이거나 이미 청소가 된 경우

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

    // 바라보는 방향 기준 앞쪽
    dir[0] = pair<int, int>(-1, 0); // 북
    dir[1] = pair<int, int>(0, 1);  // 동
    dir[2] = pair<int, int>(1, 0);  // 남
    dir[3] = pair<int, int>(0, -1); // 서

    clean(board, r, c, d);
    cout << answer;

    return 0;
}*/