/*#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main(void) {
	int max_cnt = 0;
	string name;
	map<string, int> m;

	freopen("input.txt", "r", stdin);

	while (1) {
		getline(cin, name, '\n');
		if (name == "") break; // 데이터가 없는 경우

		auto p = m.find(name);
		if (p == m.end())  // 없는 경우 새로 추가
			m[name] = 1;
		else
			p->second += 1;

		max_cnt++;
		if (cin.eof()) break;
	}

	for (auto& p : m)
		printf("%s %.4f\n", p.first.c_str(), (double)p.second * 100.0 / max_cnt);


	return 0;
}*/