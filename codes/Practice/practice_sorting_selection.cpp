#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selection_sorting(vector<int>& arr) {
	int size = arr.size();

	for (int i = 0; i < size; i++) {
		int k = i;
		for (int j = i + 1; j < size; j++) 
			if (arr[k] > arr[j]) k = j;

		swap(arr[i], arr[k]); 
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

	selection_sorting(arr);



	return 0;
}