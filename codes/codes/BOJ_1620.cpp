/*#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
	int N, M;
	int No = 1;
	map<int, string> m1; // 번호 순
	map<string, int> m2; // 이름 순

	// 문자열 입출력 시, 특히 입력의 양이 많을 경우 다음 선언을 꼭 해준다.
	// 이는 입출력을 통한 시간 초과를 방지하기 위함이다.
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// 도감 입력
	while (N--) {
		string name;
		cin >> name;
		m1[No] = name;
		m2[name] = No;

		No++;
	}

	// 검색

	while (M--) {
		string search;
		cin >> search;

		int s_no = atoi(search.c_str());
		if (s_no == 0) { // 이름 검색
			auto p = m2.find(search);
			cout << p->second << "\n";
		}
		else {
			auto p = m1.find(s_no);
			cout << p->second << "\n";
		}
	}
	return 0;
}*/