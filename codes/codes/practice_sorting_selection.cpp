/*
#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void selection_sorting(vector<int>& arr) {
	// in-place : 주어진 공간에서만 정렬이 일어남
	int size = arr.size();

	for (int i = 0; i < size; i++) { // i : 현재 정렬되어야할 원소의 인덱스
		int k = i;
		for (int j = i + 1; j < size; j++) // j : 가장 작은 원소를 찾는 인덱스 /unstable : 가장 마지막으로 작은 원소를 선택
			if (arr[i] > arr[j])k = j;

		swap(arr[i], arr[k]); // i번 반복 동안 항상 최솟값이 arr[i]에 저장되므로, 원소 바꿈의 횟수가 N * N 으로 고정되어 있음.
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