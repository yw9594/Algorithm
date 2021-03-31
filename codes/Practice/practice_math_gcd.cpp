/*#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include "show_info.h"

using namespace std;

/////////////////////////////////////////////////// ���� Header ///////////////////////////////////////////////////

int gcd(int a, int b) {

	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int gcd_recursive(int a, int b) {
	int r = a % b;
	if (r == 0) return b;
	else return gcd_recursive(b, r);
	
}

int main(void) {
	freopen("input.txt", "r", stdin);
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b;
	cin >> a >> b;

	int g = gcd(a, b);
	int l = a * b / g;
	cout << g << "\n" << l << "\n";


	return 0;
}*/