/*#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

struct Point {
	int ms;
	int type; // 0:처리시작, 1:응답 완료

	bool operator<(const Point& arg) {
		return this->ms < arg.ms;
	}
};

vector<Point> time_line;

void dateToMs(string& date, vector<Point>& time_line) {
	// 분할
	string
		h = date.substr(11, 2),
		m = date.substr(14, 2),
		s = date.substr(17, 2),
		ms = date.substr(20, 3),
		p = date.substr(24, date.length() - 1 - 24)
		;

	// 응답 시간 저장
	int res_t =
		stoi(h) * 3600000 +
		stoi(m) * 60000 +
		stoi(s) * 1000 +
		stoi(ms);
	time_line.push_back({
		res_t,
		1 });

	// 처리 시간 저장 
	string
		t_s = p.substr(0, 1),
		t_ms = (p[1] == '.') ? p.substr(2, 5) : "000";

	if (t_ms.length() == 2) t_ms += "0";
	else if (t_ms.length() == 1) t_ms += "00";

	int p_t =
		stoi(t_s) * 1000 +
		stoi(t_ms);

	time_line.push_back({
		res_t - p_t + 1,
		0
		});

}

int linear_check(vector<Point>& time_line) {
	vector<Point> req, res;
	int ans = 0;
	int stk = 0, N = time_line.size();

	// req/res 구분
	for (int i = 0; i < N; i++) {
		if (time_line[i].type == 0)
			req.push_back(time_line[i]);
		else
			res.push_back(time_line[i]);
	}

	// 변수 초기화
	int head = 999, rear = 0; // 1~0초
	int req_idx = 0, res_idx = 0;
	const int lim = 23 * 3600000 + 59 * 60000 + 59 * 1000 + 999; // 한계


	// 초기 처리량
	for (auto& r : req) {
		if (r.ms <= head) {
			stk++;
			req_idx++;
		}
		else break;
	}
	ans = stk;

	// 최대 처리량 찾기
	while (head <= lim) {
		// 새로 처리하는 요청
		for (; req_idx < N / 2; req_idx++) {
			if (req[req_idx].ms <= head)
				stk++;
			else break;
		}

		// 처리가 완료된 요청 제거
		for (; res_idx < N / 2; res_idx++) {
			if (res[res_idx].ms < rear)
				stk--;
			else break;
		}

		// 최대 처리 기록시 추가
		ans = ans > stk ? ans : stk;

		head++;
		rear++;
	}
	return ans;
}

int solution(vector<string> lines) {
	int answer = 0;

	vector<Point> time_line;

	for (auto& log : lines)
		dateToMs(log, time_line);

	sort(time_line.begin(), time_line.end());

	answer = linear_check(time_line);


	return answer;
}*/