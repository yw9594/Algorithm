/*#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sorting(vector<int>& arr, int start, int end) {
	if (start >= end) return;
	else {
		int p = start, i = start + 1, j = end; // pivot, low, high
		while (1) {
			// unstable,  low or high 어느 쪽이던..
			while (i <= end && arr[i] < arr[p]) // pivot보다 큰 조건일 때까지 low 증가
				i++;
			while (j >= start + 1 && arr[j] >= arr[p]) j--;  // pivot보다 작은 값이 때까지 감소

			if (i > j) {
				int mid = j;
				swap(arr[p], arr[j]); // pivot과 high 교환
				quick_sorting(arr, start, mid - 1); // 좌배열 정렬, mid-1이 0보다 작아질 수 있다.(오름차순 기준, 이미 정렬이 되어있는 경우)
				quick_sorting(arr, mid + 1, end); // 우배열 정렬, mid+1이 end보다 커질수 있다.(내림차순 기준, 이미 정렬이 되어있는 기준)
				break;
			}
			else
				swap(arr[i], arr[j]);

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

	quick_sorting(arr, 0, arr.size() - 1);

	int len = arr.size();
	for (int i = 0; i < len; i++)
		cout << arr[i] << "\n";

	return 0;
}*/