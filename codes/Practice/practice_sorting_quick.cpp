#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void quick_sorting(vector<int>& arr, int start, int end) {
	if (start >= end) return;
	else {
		int p = start, i = start + 1, j = end;
		while (1) {
			while (i <= end && arr[i] < arr[p]) i++;
			while (j >= start + 1 && arr[j] >= arr[p]) j--; 
			
			if (i > j) {
				int mid = j;
				swap(arr[p], arr[j]); // pivot�� high ��ȯ
				quick_sorting(arr, start, mid - 1); // �¹迭 ����, mid-1�� 0���� �۾��� �� �ִ�.(�������� ����, �̹� ������ �Ǿ��ִ� ���)
				quick_sorting(arr, mid + 1, end); // ��迭 ����, mid+1�� end���� Ŀ���� �ִ�.(�������� ����, �̹� ������ �Ǿ��ִ� ����)
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
}