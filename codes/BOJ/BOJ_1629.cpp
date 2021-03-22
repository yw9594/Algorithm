///*
//	summary.
//		fast exponetial computing.
//	point. 
//		divide and conquer. 
//*/
//
//#include <iostream>
//using namespace std;
//
//typedef long long int ll;
//
//ll fastPow(ll & A, ll B, ll &C) {
//	if (B == 1) return A%C;
//
//	if (B % 2) return (A * fastPow(A, B-1, C)) % C;
//	else {
//		ll res = fastPow(A, B / 2, C);
//		return (res * res)%C;
//	}
//}
//
//int main(void) {
//	ll A, B, C;
//
//	freopen("input.txt", "r", stdin);
//
//	std::ios::sync_with_stdio(false);
//
//	cin >> A >> B >> C;
//
//	cout << fastPow(A, B, C) << "\n";
//
//
//	return 0;
//}