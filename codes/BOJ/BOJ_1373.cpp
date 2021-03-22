/*#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	string bin;
	string answer;


	cin >> bin;

	int len = bin.size(), offset = 0;
	int cnt = 0, n = 0;

	if (len == 0) {
		cout << "\n";
		return 0;
	}

	if (len % 3 != 0) {
		offset = 3 - (len % 3);
		for (int i = 0; i < offset; i++)
			bin = "0" + bin;
		len = bin.size();
	}
	answer.resize(len / 3);

	for (int i = len - 1; i >= 0; i--) {
		n += ((bin[i] - '0') << cnt);
		cnt++;

		if (cnt % 3 == 0) {
			answer[i / 3] = (char)(n + '0');
			cnt = n = 0;
		}
	}

	len = answer.size();
	for (int i = 0; i < len; i++) {
		if (answer[i] != '0') {
			answer = answer.substr(i);
			break;
		}

	}

	cout << answer << "\n";

	return 0;
}*/