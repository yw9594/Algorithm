#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> makeTable(string str) {
	int len = str.length();
	vector<int> table(len, 0); 

	// i:surfix index / j:prefix index
	int j = 0;
	for (int i = 1; i < len; i++) {
		while (j > 0 && str[i] != str[j]) // prefix�� surfix�� �ܾ �ٸ� ���.
			j = table[j - 1];             // prefix index�� prefix==surfix�� ������ �����Ŵ.
		if (str[i] == str[j])
			table[i] = ++j;
	}
	return table;
}

vector<int> kmp(string & s, string & p) {
	int n = s.size(), m = p.size();
	vector<int> pi = makeTable(p); // pi ���̺�
	vector<int> ans; // p ���ڿ��� �����ϴ� �κ��� �ε���.
	
	int j = 0;
	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j]) 
			j = pi[j - 1];

		if (s[i] == p[j]) {
			if (j == m - 1) { 
				ans.push_back(i-m+1); 
				j = pi[j];			  
			}
			else j++;
		}
	}	
	return ans;
}


int main(void) {
	string s = "abcabc";
	string p = "abc";
	vector<int> ans = kmp(s, p);

	for (auto & a : ans)
		printf("%d ", a);

	return 0;
}