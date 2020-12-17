//#include <iostream>
//
//using namespace std;
//
//int func2(int arr[], int N) {
//	int check[101] = { 0 };
//
//	for (int i = 0; i < N; i++) {
//		if (check[100 - arr[i]]) return 1;
//		check[arr[i]] = 1;
//	}
//
//	return 0;
//}
//
//
//int main(void) {
//	int arr[4] = {4, 13, 63, 87};
//	int N = 4;
//
//	cout << func2(arr, N) << endl;
//
//	return 0;
//}