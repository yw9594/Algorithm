/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int L, C;
vector<char> arr;

int is_a[26] = { 0 };

void solution(vector<char>& ans, int index, int a_cnt, int b_cnt) {
	if (index == C) {
		if (ans.size() == L && (a_cnt >= 1 && b_cnt >= 2)) {
			for (auto& e : ans)
				cout << e;
			cout << "\n";
		}
	}
	else {
		// index ��° ���� �����ϴ� ���
		char cur_c = arr[index];
		ans.push_back(cur_c);

		solution(ans,
			index + 1,
			a_cnt + (is_a[cur_c - 'a'] ? 1 : 0),
			b_cnt + (is_a[cur_c - 'a'] ? 0 : 1)
		);

		ans.pop_back();

		// index ��° ���� ���� ���ϴ� ���
		solution(ans,
			index + 1,
			a_cnt,
			b_cnt
		);
	}
	return;

}



int main(void) {
	freopen("input.txt", "r", stdin);

	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	// �Է� �ޱ�
	cin >> L >> C;
	arr = vector<char>(C);
	for (int i = 0; i < C; i++)
		cin >> arr[i];

	// C���� ���ڸ� �������� �����ϱ�
	sort(arr.begin(), arr.end());

	// ����� �� ����
	is_a['a' - 'a'] = 1;
	is_a['e' - 'a'] = 1;
	is_a['i' - 'a'] = 1;
	is_a['o' - 'a'] = 1;
	is_a['u' - 'a'] = 1;

	vector<char> ans;
	solution(ans, 0, 0, 0);



	return 0;
}*/