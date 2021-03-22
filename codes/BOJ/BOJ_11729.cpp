/*
	point.
		1) Hanoi Tower. exponential Time Complexity 
		2) set unused 
*

#include <iostream>

using namespace std;;

void Hanoi(int a, int b, int n) { //  n'th tower move a to b pole.
	if (n == 1) {
		cout << a << " " << b << "\n";
		return;
	}

	int c = 6 - a - b;	// c : unused tower number. a + b + c = 6
	Hanoi(a, c, n-1);
	cout << a << " " << b << "\n";
	Hanoi(c, b, n-1);
}

int main(void) {
	int N;
	std::ios::sync_with_stdio(false);
	cin >> N;

	Hanoi(1, 3, N);

	return 0;
}*/