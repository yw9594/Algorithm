#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
	vector<int> sorted;
	int i = start, j = mid + 1;

	while (i <= mid && j <= end) { // �Ǽ�
		if (arr[i] <= arr[j]) sorted.push_back(arr[i++]);
		else sorted.push_back(arr[j++]);
	}

	while (i <= mid) sorted.push_back(arr[i++]);
	while (j <= end) sorted.push_back(arr[j++]);

	int len = sorted.size();
	for (int k = 0, i = start; k < len; k++, i++) {
		arr[i] = sorted[k];
	}

	return;
}

void merge_sorting(vector<int>& arr, int start, int end) {
	if (start == end) return;
	else {
		int mid = (start + end) / 2;
		merge_sorting(arr, start, mid);
		merge_sorting(arr, mid + 1, end);
		merge(arr, start, mid, end);
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
	
	merge_sorting(arr, 0, arr.size()-1);

	return 0;
}