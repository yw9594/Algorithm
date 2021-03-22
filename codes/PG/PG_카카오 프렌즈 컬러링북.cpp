/*#include <vector>
#include <queue>

using namespace std;

struct pos {
    int i, j;
};

int number_of_area;
int max_size_of_one_area;
vector<int> dx;
vector<int> dy;
vector<vector<int>> pushed;

int BFS(int start_i, int start_j, int m, int n, vector<vector<int>>& picture) {
    int size_of_area = 0;
    int color = picture[start_i][start_j];

    queue<pos> q;
    q.push({ start_i, start_j });
    pushed[start_i][start_j] = 1;

    while (!q.empty()) {
        pos c_pos = q.front();
        q.pop();

        size_of_area++;

        for (int k = 0; k < 4; k++) {
            pos n_pos = { c_pos.i + dx[k], c_pos.j + dy[k] };
            if (n_pos.i < 0 || n_pos.i >= m || n_pos.j < 0 || n_pos.j >= n || // 범위 초과
                picture[n_pos.i][n_pos.j] != color ||                // 색상 다름
                pushed[n_pos.i][n_pos.j])                            // 이미 체크함 
                continue;
            q.push(n_pos);
            pushed[n_pos.i][n_pos.j] = 1;
        }
    }

    return size_of_area;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {

    number_of_area = 0;
    max_size_of_one_area = 0;
    dx = { -1, 1, 0, 0 };
    dy = { 0, 0, -1, 1 };
    pushed = vector<vector<int>>(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] && !pushed[i][j]) {
                number_of_area++;
                int size_of_area = BFS(i, j, m, n, picture);

                if (size_of_area > max_size_of_one_area)
                    max_size_of_one_area = size_of_area;
            }
        }
    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}*/