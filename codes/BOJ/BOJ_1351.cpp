/*#include <iostream>
#include <map>
#include <string>

using namespace std;

long long int P, Q;
map<long long int, long long int> m;	// <Ai index, Ai value>

long long int recursive(long long int n) {
	if (n == 0) return 1;

	long long int idx_left = n / P, idx_right = n / Q;
	long long int left, right;

	auto Ap = m.find(idx_left);
	if (Ap != m.end()) left = Ap->second;
	else {
		left = recursive(idx_left);
		m[idx_left] = left; // map을 통한 메모이제이션이 핵심. 
	}

	auto Aq = m.find(idx_right);
	if (Aq != m.end()) right = Aq->second;
	else {
		right = recursive(idx_right);
		m[idx_right] = right;
	}

	return left + right;
}

int main(void) {
	long long int answer, N;
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> P >> Q;

	answer = recursive(N);

	cout << answer << "\n";

	return 0;
}*/