/*#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int N = s.size();

    string str_ans = s;

    for (int d = 1; d <= N / 2; d++) {
        string cand = "";
        int i = 0, j = i + d;
        int cnt = 1;

        while (i < N) {
            string cur_sub = s.substr(i, d);
            while (j <= N) {
                if (j == N) break;
                if (cur_sub.compare(s.substr(j, d)) == 0) {
                    cnt++;
                    j += d;
                }
                else break;
            }
            if (cnt >= 2) cand += (to_string(cnt) + cur_sub);
            else cand += cur_sub;
            i = j;
            j = i + d;
            cnt = 1;
        }
        if (str_ans.size() > cand.size())
            str_ans = cand;
    }
    answer = str_ans.size();

    return answer;
}*/