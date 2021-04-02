#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main(void) {
	// freopen("input.txt", "r", stdin);

	stringstream ss;
	vector<string> rows = {
		"1 aaaa 178.14",
		"2 bbbb 180.99",
		"3 cccc 167.22",
	};

	for (auto& row : rows) {
		int num;
		string name;
		float height;

		ss.str(row);

		while (ss >> num >> name >> height)
			cout << num << " " << name << " " << height << "\n";
		ss.clear(); 

		while (!ss.eof()) {
			ss >> num >> name >> height;
			cout << num << " " << name << " " << height << "\n";
		}
		ss.clear();
	}

	return 0;
}