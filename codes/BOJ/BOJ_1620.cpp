/*#include <iostream>
#include <string>
#include <map>
#include <cstdlib>

using namespace std;

int main(void) {
	int N, M;
	int No = 1;
	map<int, string> m1; // ��ȣ ��
	map<string, int> m2; // �̸� ��

	// ���ڿ� ����� ��, Ư�� �Է��� ���� ���� ��� ���� ������ �� ���ش�.
	// �̴� ������� ���� �ð� �ʰ��� �����ϱ� �����̴�.
	std::istream::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	// ���� �Է�
	while (N--) {
		string name;
		cin >> name;
		m1[No] = name;
		m2[name] = No;

		No++;
	}

	// �˻�

	while (M--) {
		string search;
		cin >> search;

		int s_no = atoi(search.c_str());
		if (s_no == 0) { // �̸� �˻�
			auto p = m2.find(search);
			cout << p->second << "\n";
		}
		else {
			auto p = m1.find(s_no);
			cout << p->second << "\n";
		}
	}
	return 0;
}*/