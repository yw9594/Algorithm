/* 
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	// freopen("input.txt", "r", stdin);

	// 1. ���� ���� �˻�
	char c = '@';
	cout << strchr("!@#$%", c) << "\n"; // ������ 0, ������ �ּ�

	// 2. ���ڿ� �˻�
	string str = "abcabcabcabcabc";
	string sub = "abc";
	vector<int> arr;

	int idx = 0;
	while ((idx = str.find(sub, idx)) != -1) {
		idx += sub.size();
		arr.push_back(idx);
	}
	for (auto& i : arr) cout << i << " ";
	cout << "\n";



	return 0;
}*/