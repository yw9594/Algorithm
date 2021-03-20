/*#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	// freopen("input.txt", "r", stdin);

	stringstream ss;
	vector<string> rows = {
		"1 aaaa 178.14",
		"2 bbbb 180.99",
		"3 cccc 167.22",
	};

	for (auto& row : rows) {
		int num;
		string name;
		float height;

		// 문자열 세팅
		ss.str(row);

		// 연산자 사용하기
		while (ss >> num >> name >> height)
			cout << num << " " << name << " " << height << "\n";
		ss.clear(); // 기존의 stringstream을 재사용하려면 반드시 clear를 호출. eof bit 제거

		// eof 사용하기(문자열 끝까지 읽어들임.
		while (!ss.eof()) {
			ss >> num >> name >> height;
			cout << num << " " << name << " " << height << "\n";
		}
		ss.clear(); // 기존의 stringstream을 재사용하려면 반드시 clear를 호출. eof bit 제거
	}

	return 0;
}*/