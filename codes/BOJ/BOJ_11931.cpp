/*#include <iostream>
#include <algorithm>

using namespace std;

class pred {
public: 
	bool operator()(int a, int b) {
		return a < b;
	}
};

int main(void) {
	int N;
	int arr[1000000];

	freopen("input.txt", "rt", stdin);

	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d", arr+i);

	sort(arr, arr + N, pred());

	for (int i = 0; i < N; i++)
		printf("%d\n", arr[i]);

	return 0;
}*/