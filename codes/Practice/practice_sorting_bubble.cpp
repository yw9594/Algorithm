#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bubble_sorting(vector<int>& arr) {
	int size = arr.size();

	for (int i = 0; i < size; i++) { 
		for (int j = 0; j < size - 1 - i; j++) { 
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
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

	bubble_sorting(arr);

	return 0;
}