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

void solution(vector<int >& arr) {
	// M���� ��� ä�� ���
	if (arr.size() == M) {
		for (auto& k : arr)
			cout << k << " ";
		cout << "\n";
		return;
	}

	// ���� 
	for (int i = 1; i <= N; i++) {

		// n�� �����ϴ� ���
		arr.push_back(i);

		solution(arr);

		arr.pop_back();

		// n�� ���� ���ϴ� ��� 
		checked[i] = 0;

	}
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	vector<int> arr;

	solution(arr);


	return 0;
}*/