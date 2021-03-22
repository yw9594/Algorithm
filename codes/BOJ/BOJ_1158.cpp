///*
//	개요 : 백준 1158번 요세푸스 문제
//	요약 :
//		배열을 사용해 문제를 해결한다.
//	방법 :
//		정수를 하나 출력할 때마다 배열을 앞으로 당겨 정수를 제거한다.
//	핀포인트 :
//		실제로 배열의 길이를 줄이는 방법으로 문제를 해결한다.
//*/
//
//#include <iostream>
//
//int main(void) {
//	int N, K, arr[5001], cur_i = 0;
//
//	scanf("%d %d", &N, &K);
//	for (int i = 1; i <= N; i++) arr[i] = i;
//
//	printf("<");
//	while (N > 0) {
//		cur_i = (cur_i + K) % N;
//		if (cur_i == 0) cur_i = N;
//
//		if (N == 1) printf("%d>", arr[cur_i]);
//		else {
//			printf("%d, ", arr[cur_i]);
//			for (int i = cur_i; i < N; i++) {
//				arr[i] = arr[i + 1];
//			}
//			cur_i--;
//		}
//		N--; // 배열 길이 감소
//	}
//
//
//	return 0;
//
//}