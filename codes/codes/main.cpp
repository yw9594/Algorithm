/* 라이브러리 & 메소드
// Headers
#include <iostream>

#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>

#include <string>
#include <sstream>   // ex) stringstream

#include <cmath>
#include <cctype>    // ex)isdigit..

#include "show_info.h"

// input
std::istream>::sync_with_stdio(false);
cin.tie(NULL);
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

vector<string> split(string& str, char delim=' ') {
	vector<string> toks;
	stringstream ss(str);
	string tok;

	while (getline(ss, tok, delim)) toks.push_back(tok);

	return toks;
}

int main(void) {
	// freopen("input.txt", "r", stdin);
	vector<string> toks;

	string str1= "1 2 3 4 5";
	string str2 = "1n2n3n4n";

	toks = split(str1);
	for (auto& e : toks) cout << e << " ";
	cout << "\n";

	toks = split(str1, 'n');
	for (auto& e : toks) cout << e << " ";
	cout << "\n";

	
	return 0;
}