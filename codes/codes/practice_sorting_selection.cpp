/*
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void selection_sorting(vector<int>& arr) {
	// in-place : �־��� ���������� ������ �Ͼ
	int size = arr.size();

	for (int i = 0; i < size; i++) { // i : ���� ���ĵǾ���� ������ �ε���
		int k = i;
		for (int j = i + 1; j < size; j++) // j : ���� ���� ���Ҹ� ã�� �ε��� /unstable : ���� ���������� ���� ���Ҹ� ����
			if (arr[i] > arr[j])k = j;

		swap(arr[i], arr[k]); // i�� �ݺ� ���� �׻� �ּڰ��� arr[i]�� ����ǹǷ�, ���� �ٲ��� Ƚ���� N * N ���� �����Ǿ� ����.
	}
	return;
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> arr(N);
	for (int i = 0; i < N; i++) cin >> arr[i];

	show_array(arr);

	selection_sorting(arr);

	show_array(arr);


	return 0;
}
*/