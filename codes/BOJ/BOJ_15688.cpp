/*#include <iostream>
#include <cstdlib>

using namespace std;

int main(void) {
	int N, F;
	int base, ans;

	freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	scanf("%d", &F);

	base = 100 * (N / 100);
	for (int i = 0; i < 100; i++) {
		if (!(base % F)) {
			ans = base;
				break;
		}
		base += 1;
	}
	printf((ans%100<10) ? "0%d\n" : "%d\n", ans%100);

	return 0;
}*/