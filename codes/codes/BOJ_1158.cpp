///*
//	���� : ���� 1158�� �似Ǫ�� ����
//	��� :
//		�迭�� ����� ������ �ذ��Ѵ�.
//	��� :
//		������ �ϳ� ����� ������ �迭�� ������ ��� ������ �����Ѵ�.
//	������Ʈ :
//		������ �迭�� ���̸� ���̴� ������� ������ �ذ��Ѵ�.
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
//		N--; // �迭 ���� ����
//	}
//
//
//	return 0;
//
//}