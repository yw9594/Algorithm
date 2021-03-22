/* 라이브러리 & 메소드
// Headers
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

// input
std::istream>::sync_with_stdio(false);
cin.tie(NULL);
*/
/*
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

using i_p = pair<int, int>;

int ans = 0;
vector<int> arr;
vector<deque<i_p>> board; // 노드 번호 : (다음 노드, 점수)

i_p move(i_p& c_p, int n, vector<i_p>& P) {
	i_p o_p = c_p; // 이전 말 상태

	// 다음 노드 정보
	i_p  n_p = { c_p.first,  -1 }; // -1은 더미 데이터

	// 출발선이 파란 선일 경우
	if (n_p.first == 5 ||
		n_p.first == 10 ||
		n_p.first == 15) {
		n_p = board[n_p.first][1];
		n--;
	}
	// 칸 이동
	while (n--) {
		if (n_p.first == 32) break;

		n_p = board[n_p.first][0];
	}

	// 말 이동 
	c_p = {
		n_p.first,
		c_p.second + n_p.second // 누적 점수
	};

	// 이전 위치 반환
	return o_p;
}

bool check(i_p& c_p, vector<i_p>& P) {
	int cnt = 0;
	// 도착점은 허용
	if (c_p.first == 32)
		return true;


	// 같은 위치의 말이 있는 경우 불가능
	for (int i = 0; i < 4; i++) {
		if (c_p.first == P[i].first) {
			cnt++;
		}
	}
	return cnt > 1 ? false : true;
}

void solution(int idx, vector<i_p>& P) {
	cout << idx << "=";
	for (int i = 0; i < 4; i++)
		cout << "(" << P[i].first << " " << P[i].second << ") ";
	cout << "\n";
	// 이동 종료
	if (idx == 10) {
		int tmp = 0;
		for (int i = 0; i < 4; i++) tmp += P[i].second;
		ans = ans > tmp ? ans : tmp;
		return;
	}

	// 말 이동 시키기
	for (int p = 0; p < 4; p++) {
		// 현재 이동할 말 
		i_p& c_p = P[p];

		// 도착한 경우 패스
		if (c_p.first == 32) continue;

		// 이동
		i_p o_p = move(c_p, arr[idx], P);

		// 위치 다음 이동
		if (check(c_p, P)) {

			solution(idx + 1, P);
		}
		// 되돌리기
		c_p = o_p;
	}

	return;
}


int main(void) {
	freopen("input.txt", "r", stdin);

	arr = vector<int>(10);
	for (int i = 0; i < 10; i++)
		cin >> arr[i];

	// 보드 초기화
	board = vector<deque<i_p>>(33, deque<i_p>()); // 33개의 노드, 0:시작, 32:도착
	for (int i = 0; i < 20; i++)				  // 메인 루트
		board[i].push_back({ i + 1, (i + 1) * 2 });

	// 10~25 사이
	board[5].push_back({ 21, 13 });
	board[21].push_back({ 22, 16 });
	board[22].push_back({ 23, 19 });
	board[23].push_back({ 29, 25 });

	// 20~25 사이
	board[10].push_back({ 24, 22 });
	board[24].push_back({ 25, 24 });
	board[25].push_back({ 29, 25 });

	// 30~25 사이
	board[15].push_back({ 26, 28 });
	board[26].push_back({ 27, 27 });
	board[27].push_back({ 28, 26 });
	board[28].push_back({ 29, 25 });

	// 25~40 사이
	board[29].push_back({ 30, 30 });
	board[30].push_back({ 31, 35 });
	board[31].push_back({ 20, 40 });

	// ~도착
	board[20].push_back({ 32, 0 });

	// 풀이 
	vector<i_p> P(4, { 0, 0 }); // (말 위치, 말이 획득한 점수)
	solution(0, P);

	cout << ans << "\n";

	return 0;
}*/