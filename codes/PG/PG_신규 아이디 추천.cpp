/*#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <list>

using namespace std;

struct IdGenerator {
	string str_id;
	list<char> list_id;

	IdGenerator(string new_id) {
		this->str_id = new_id; ;
		this->list_id = to_list(new_id);
	}
	list<char> to_list(string id) {
		list<char> tmp;
		for (auto& c : id)
			tmp.push_back(c);
		return tmp;
	}
	string to_string(list<char> id) {
		string tmp = "";
		for (auto& c : id)
			tmp += c;
		return tmp;
	}

	void to_lower(list<char>& id) { // 소문자화
		for (auto& c : id)
			c = tolower(c);
		return;
	}

	void not_allowed(list<char>& id) { // 포함 금지 문자 제거
		vector<list<char>::iterator> del_c;
		for (auto it = id.begin(); it != id.end(); it++) {
			char& cur_c = *it;
			if ((cur_c >= 'a' && cur_c <= 'z') ||
				(cur_c >= '0' && cur_c <= '9') ||
				cur_c == '-' || cur_c == '_' || cur_c == '.')
				continue;
			else
				del_c.push_back(it);
		}
		for (int i = del_c.size() - 1; i >= 0; i--)
			id.erase(del_c[i]);
		del_c.clear();
	}

	void seq_dot(list<char>& id) { // 연속 점 제거
		vector<list<char>::iterator> del_c;
		if (id.size() != 0) {
			auto it = id.begin();
			char old_c = *(it++);
			for (; it != id.end(); it++) {
				char& cur_c = *it;
				if (cur_c == '.' && old_c == '.')
					del_c.push_back(it);
				old_c = cur_c;
			}
			for (int i = del_c.size() - 1; i >= 0; i--)
				id.erase(del_c[i]);
			del_c.clear();
		}
		return;
	}

	void strip_dot(list<char>& id) { // 끝 점 제거
		vector<list<char>::iterator> del_c;
		if (id.size() != 0) {
			if (*id.begin() == '.')
				id.erase(id.begin());

			if (id.size() != 0) {
				if (id.back() == '.') {
					auto it = id.end();
					it--;
					id.erase(it);
				}
			}
		}
		return;
	}
	void is_empty(list<char>& id) {
		if (id.size() == 0)
			id.push_back('a');
	}

	void length_check(list<char>& id) {
		if (id.size() > 15) {
			auto it = id.begin();
			for (int i = 0; i < 15; it++, i++) {}
			id.erase(it, id.end());

			seq_dot(id);
			strip_dot(id);
			is_empty(id);
			length_check(id);
		}
		else if (id.size() < 3) {
			while (id.size() < 3)
				id.push_back(id.back());
		}

	}

	string generate() {
		to_lower(list_id);
		not_allowed(list_id);
		seq_dot(list_id);
		strip_dot(list_id);
		is_empty(list_id);
		length_check(list_id);
		return to_string(list_id);
	}

};

int main(void) {
	// freopen("input.txt", "r", stdin);

	string new_id = "abcdefghijklmn.p";

	IdGenerator gen(new_id);

	cout << gen.generate() << "\n";

	return 0;
}*/