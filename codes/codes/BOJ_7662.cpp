/*#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <algorithm>

using namespace std;

int main(void) {
	int T;
	string dummy;

	std::istream::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);

	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		map<int, int> m; // 가장 큰 수 : 오른쪽, 가장 작은 수 : 왼쪽

		cin >> N;
		getline(cin, dummy, '\n'); // 개행 제거

		while (N--) {
			string cmd;
			getline(cin, cmd, '\n');

			if (cmd[0] == 'I') {
				string num_str = cmd.substr(2);
				int num = atoi(num_str.c_str());

				if (m.find(num) != m.end()) m[num] += 1;
				else  m[num] = 1;
			}
			else if (cmd[0] == 'D') {
				if (m.empty()) continue; // 비어있을 경우 무시
				else if (cmd[2] == '1') { // 최댓값 삭제
					auto iter = m.rbegin();
					if ((iter->second) == 1) m.erase(iter->first);
					else m[iter->first] -= 1;
				}
				else { // 최솟값 삭제
					auto iter = m.begin();
					if ((iter->second) == 1) m.erase(iter->first);
					else m[iter->first] -= 1;
				}
			}

		}
		if (m.size() == 0) cout << "EMPTY\n";
		else cout << m.rbegin()->first << " " << m.begin()->first << "\n";

	}

	return 0;
}*/