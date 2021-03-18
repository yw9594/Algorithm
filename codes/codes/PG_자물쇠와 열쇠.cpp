/*#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> make_board(vector<vector<int>>& lock) {
    int N = lock.size();
    vector<vector<int>> board(3 * N, vector<int>(3 * N, 0));
    for (int i = N; i < 2 * N; i++)
        for (int j = N; j < 2 * N; j++)
            board[i][j] = lock[i - N][j - N];
    return board;
}
void try_solve(int s_i, int s_j, vector<vector<int>>& key, vector<vector<int>>& board, int flag) {
    int N = key.size();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            board[s_i + i][s_j + j] += (key[i][j] * flag);
        }
    }
}
bool is_unlock(vector<vector<int>>& board) {
    int N = board.size() / 3;
    for (int i = N; i < 2 * N; i++) {
        for (int j = N; j < 2 * N; j++) {
            if (board[i][j] >= 2 || board[i][j] == 0) return false;
        }
    }
    return true;
}
void rotate(vector<vector<int>>& key) {
    int M = key.size();

    vector<vector<int>> temp(M, vector<int>(M, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            temp[j][M - 1 - i] = key[i][j];
        }
    }
    key = temp;
}

bool check(int s_i, int s_j, vector<vector<int>>& key, vector<vector<int>>& board) {
    int M = key.size();
    for (int k = 0; k < 4; k++) {
        rotate(key);

        try_solve(s_i, s_j, key, board, 1); // ¿­¼è ³¢¿ì±â             
        if (is_unlock(board))
            return true;
        try_solve(s_i, s_j, key, board, -1); // ¿­¼è »©±â

    }
    return false;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int N = lock.size();
    vector<vector<int>> board = make_board(lock);

    for (int i = 0; i <= 2 * N; i++) {
        for (int j = 0; j <= 2 * N; j++) {
            if (check(i, j, key, board))
                return true;
        }
    }

    return false;
}*/