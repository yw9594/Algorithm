/*#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void insertion_sorting(vector<int>& arr) {
//	in - place : 주어진 공간에서만 정렬이 일어남
	int size = arr.size();

	for (int i = 1; i < size; i++) { // i : 삽입하려는 원소의 인덱스. (0~i-1까지는 정렬된 카드이다.) 
		for (int j = i; j >0; j--) { // j : i번째 카드가 들어갈 위치를 찾는 인덱스 
			if (arr[j] < arr[j - 1]) // 작을 때만 변경하므로 stable 
				swap(arr[j], arr[j - 1]);
			else  // 카드가 들어갈 위치를 찾았다면 break. 만약 애초에 배열이 정렬되어있다면 O(N)의 기적의 정렬속도를 보여줌(..)
				break; 
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

	insertion_sorting(arr);

	show_array(arr);

	
	return 0;
}*/