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

int N, M;
int checked[9] = { 0 };

void solution(int idx, vector<int >& arr) {
	// M���� ��� ä�� ���
	if (arr.size() == M) {
		for (auto& k : arr)
			cout << k << " ";
		cout << "\n";
		return;
	}

	// ���� 
	for (int i = idx; i <= N; i++) {

		// n�� �����ϴ� ���
		if (!checked[i]) {
			arr.push_back(i);
			checked[i] = 1;

			solution(i + 1, arr);

			arr.pop_back();
			checked[i] = 0;
		}
	}

}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<int> arr;

	solution(1, arr);


	return 0;
}*/