
#include <iostream>

#include "../infos.h"

using namespace std;

int fibo(int c, int a, int b) { // c: c번째 피보나치 수 / a : fibo[i-1] / b : fibop[i-2]
	if(c<1) return b;
	else if(c==1) return a;
	else return fibo(c-1, a+b, a);
}

int main(void) {

	for(int i=0; i<10; i++) cout << fibo(i, 1, 0)<<" ";
	cout <<"\n";

	return 0;
}