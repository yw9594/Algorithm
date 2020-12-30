/*#include <iostream>
#include <vector>
#include <algorithm>
#include "sort_header.h"

using namespace std;

void insertion_sorting(vector<int>& arr) {
//	in - place : �־��� ���������� ������ �Ͼ
	int size = arr.size();

	for (int i = 1; i < size; i++) { // i : �����Ϸ��� ������ �ε���. (0~i-1������ ���ĵ� ī���̴�.) 
		for (int j = i; j >0; j--) { // j : i��° ī�尡 �� ��ġ�� ã�� �ε��� 
			if (arr[j] < arr[j - 1]) // ���� ���� �����ϹǷ� stable 
				swap(arr[j], arr[j - 1]);
			else  // ī�尡 �� ��ġ�� ã�Ҵٸ� break. ���� ���ʿ� �迭�� ���ĵǾ��ִٸ� O(N)�� ������ ���ļӵ��� ������(..)
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