#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void insertion_sorting(vector<int>& arr) {
	int size = arr.size();

	for (int i = 1; i < size; i++) { 
		for (int j = i; j >0; j--) { 
			if (arr[j] < arr[j - 1]) 
				swap(arr[j], arr[j - 1]);
			else 
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

	insertion_sorting(arr);
	
	return 0;
}