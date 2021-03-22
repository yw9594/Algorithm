/*#include <string>
#include <vector>
#include <iostream>

using namespace std;

inline int divide(string& s) {
    int a = 0, b = 0;
    int i = 0;
    for (; i < s.size(); i++) {
        if (s[i] == '(') a++;
        else b++;
        if (a == b) break;

    }
    return i + 1;
}
int check(string& s) {
    vector<char> stk;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') stk.push_back(s[i]);
        else {
            if (stk.empty()) return 0;
            else stk.pop_back();
        }
    }
    if (!stk.empty()) return 0;
    return 1;
}

string recursive(string& s) {
    if (s.size() == 0) return "";

    int div_idx = divide(s);
    string u = s.substr(0, div_idx);
    string v = s.substr(div_idx, s.size());

    if (check(u))
        return u += recursive(v);
    else {
        string n = "(";
        n += recursive(v);
        n += ')';
        for (int i = 1; i < u.size() - 1; i++) {
            if (u[i] == '(') n += ')';
            else n += '(';
        }
        return n;
    }
}

string solution(string p) {
    string answer = "";

    answer = recursive(p);

    return answer;
}*/