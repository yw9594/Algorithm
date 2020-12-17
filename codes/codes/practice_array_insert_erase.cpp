//#include <iostream>
//
//using namespace std;
//
//void insert(int idx, int num, int arr[], int& len) {
//	if (idx == 0) {
//		arr[idx] = num;
//	}
//	else if (idx < len) {
//		for (int i = len - 1; i >= idx; i--) arr[i + 1] = arr[i];
//		arr[idx] = num;
//	}
//	len++;
//	return;
//}
//void erase(int idx, int arr[], int& len) {
//	if (len > 0 && idx < len) {
//		if (idx == len-1) len--;
//		else {
//			for (int i = idx; i < len - 1; i++) arr[i] = arr[i + 1];
//			len--;
//		}
//	}
//	return;
//}
//void show(int arr[], int& len) {
//	for (int i = 0; i < len; i++) printf("%d ", arr[i]);
//	printf("\n");
//	return;
//}
//
//int main(void) {
//	int arr[100] = {1};
//	int len = 1;
//	
//	show(arr, len);
//	erase(0, arr, len);
//	show(arr, len);
//	insert(0, 99, arr, len);
//	show(arr, len);
//
//	return 0;
//}