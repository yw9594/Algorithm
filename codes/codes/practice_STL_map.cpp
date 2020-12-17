/*#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(void) {
	map<string, int> m; // Pred 지정 가능 : map<string, int,less<string>> map;
	
	// 1. insert/erase
	m.insert(pair<string, int>("a", 1));
	m.insert(pair<string, int>("b", 2));
	m.insert(pair<string, int>("c", 3));
	m["d"] = 4;								// 인덱싱 지원.
	m["f"] = 6;								// 인덱싱 지원.
	m.erase("b");
	

	// 2. search
	cout << "# find를 사용한 search" << endl;
	auto p = m.find("e"); // 없는 요소일 경우 end() 반환.
	if (p != m.end()) cout << p->first << " " << p->second << endl;
	else		      cout << "원소가 없습니다." << endl;

	p = m.find("c");
	for (; p != m.end();p++)
		cout << p->first << " " << p->second << endl;

	// 3.bound 찾기 (특정 원소의 bound 찾기가 편하다.)
	cout << "# bound 찾기" << endl;
	auto p1 = m.lower_bound("a"); // lower/upper bound의 의미 [p, q)의 인덱스 or (포인터)
	auto p2 = m.upper_bound("a");

	cout << p1->first << " " << p1->second << endl;
	cout << p2->first << " " << p2->second << endl;

	return 0;
}*/