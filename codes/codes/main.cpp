/*#include <string>
#include <vector>
#include <iostream> 
#include <deque>

using namespace std;

int number_of_area = 0;         // 영역 개수
int max_size_of_one_area = 0;   // 영역 최대 크기
int max_m, max_n;               // 경계 
int pushed[100][100] = { 0, };
int offset[4][2] = {
    -1, 0, // 상
    1, 0,  // 하
    0, -1, // 좌
    0, 1   // 우
};

struct elem {
    int i, j, color;
    elem(int i, int j, int color) {
        this->i = i;
        this->j = j;
        this->color = color;
    }
};

bool checkRange(int i, int j) {
    if (i < 0 || i >= max_m || j < 0 || j >= max_n) return false;
    return true;
}

void bfs(int start_i, int start_j, vector<vector<int>> & picture) {
    int cur_i = start_i, cur_j = start_j, cur_color = picture[cur_i][cur_j];
    int cur_color_area = 0;
    deque<elem> q;

    q.push_back(elem(cur_i, cur_j, cur_color)); // 첫 원소 삽입
    pushed[cur_i][cur_j] = 1;

    while (!q.empty()) {
        elem cur_elem = q.front();
        q.pop_front();


        cur_color_area++;

        for (int k = 0; k < 4; k++) {
            int next_i = cur_elem.i + offset[k][0],
                next_j = cur_elem.j + offset[k][1];

            if (checkRange(next_i, next_j) && !pushed[next_i][next_j] &&
                cur_color==picture[next_i][next_j] && picture[next_i][next_j]!=0) {
                q.push_back(elem(next_i, next_j, cur_color));
                pushed[next_i][next_j] = 1;
            }
        }

    }

    max_size_of_one_area = cur_color_area > max_size_of_one_area ? cur_color_area : max_size_of_one_area;

    return;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    max_n = n;
    max_m = m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (pushed[i][j] || picture[i][j]==0) // 이미 찾았거나, 색이 없는 경우 pass
                continue;
            else {
                number_of_area += 1;
                bfs(i, j, picture);
            }
        }
    }

    
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;

    for (int i = 0; i < 100; i++) for (int j = 0; j < 100; j++) pushed[i][j] = 0;
    max_m = max_n = number_of_area = max_size_of_one_area = 0; // 전역변수 초기화

    return answer;
}*/
/*
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int mid_idx = citations.size() / 2;

    sort(citations.begin(), citations.end());

    while (1) {
        int h = citations[mid_idx]; // 가운데 인용수

    }



    return answer;
}*/