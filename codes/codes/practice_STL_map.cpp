/*#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


int main(void) {
	map<string, int> m; // Pred ���� ���� : map<string, int,less<string>> map;
	
	// 1. insert/erase
	m.insert(pair<string, int>("a", 1));
	m.insert(pair<string, int>("b", 2));
	m.insert(pair<string, int>("c", 3));
	m["d"] = 4;								// �ε��� ����.
	m["f"] = 6;								// �ε��� ����.
	m.erase("b");
	

	// 2. search
	cout << "# find�� ����� search" << endl;
	auto p = m.find("e"); // ���� ����� ��� end() ��ȯ.
	if (p != m.end()) cout << p->first << " " << p->second << endl;
	else		      cout << "���Ұ� �����ϴ�." << endl;

	p = m.find("c");
	for (; p != m.end();p++)
		cout << p->first << " " << p->second << endl;

	// 3.bound ã�� (Ư�� ������ bound ã�Ⱑ ���ϴ�.)
	cout << "# bound ã��" << endl;
	auto p1 = m.lower_bound("a"); // lower/upper bound�� �ǹ� [p, q)�� �ε��� or (������)
	auto p2 = m.upper_bound("a");

	cout << p1->first << " " << p1->second << endl;
	cout << p2->first << " " << p2->second << endl;

	return 0;
}*/