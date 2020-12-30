/*#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void bubble_sorting(vector<int>& arr) {
	//	in - place : �־��� ���������� ������ �Ͼ
	int size = arr.size();

	for (int i = 0; i < size; i++) { // i : bubble Ƚ��, 1ȸ �ݺ��� ���� ū ���� ���������� �̵�
		for (int j = 0; j < size - 1 - i; j++) { // j: bubble �ε���. ���� ���ؿ� ���� ���Ҹ� �ٲ�. i�� �������ν� ���� ��ȿ������ ���� ����
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]); // ���� �� ���������� swap�� �߻�. �ܼ� ��ġ �ľ� �� �ٲٴ� �ͺ��� ������ ��� 
		}
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

	bubble_sorting(arr);
	show_array(arr);


	return 0;
}*/