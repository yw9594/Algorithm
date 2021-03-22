/*#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int N, max_num = 0;
	string answer;
	map<string, int, less<string>> m;

	std::istream::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	scanf("%d", &N);
	for (int n = 0; n < N; n++) {
		string name;
		cin >> name;

		auto iter = m.find(name);
		if (iter == m.end()) m[name] = 1;
		else m[name] += 1;
	}

	for (auto& p : m) {
		if (p.second > max_num) {
			max_num = p.second;
			answer = p.first;
		}
	}
	printf("%s\n", answer.c_str());

	return 0;
}*/