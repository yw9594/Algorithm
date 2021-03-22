/*#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void bubble_sorting(vector<int>& arr) {
	//	in - place : 주어진 공간에서만 정렬이 일어남
	int size = arr.size();

	for (int i = 0; i < size; i++) { // i : bubble 횟수, 1회 반복시 가장 큰 값이 오른쪽으로 이동
		for (int j = 0; j < size - 1 - i; j++) { // j: bubble 인덱스. 정렬 기준에 따라 원소를 바꿈. i를 빼줌으로써 뒤의 비효율적인 연산 제거
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]); // 정렬 중 지속적으로 swap이 발생. 단순 위치 파악 후 바꾸는 것보다 복잡한 계산 
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