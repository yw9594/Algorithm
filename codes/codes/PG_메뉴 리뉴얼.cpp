#include <string>
#include <vector>
/*#include <iostream>
#include <algorithm>

using namespace std;

struct pred {
    bool operator()(const string& a, const string& b) {
        if (a.size() == b.size()) return a < b;
        return a.size() < b.size();
    }
};

void recursive(int idx, string& order, string& subset, vector<string>& subsets) {
    if (idx == order.size()) {
        if (subset.size() >= 2) // 최소 2개 이상 메뉴
            subsets.push_back(subset);
        return;
    }
    // 포함
    subset.push_back(order[idx]);
    recursive(idx + 1, order, subset, subsets);
    subset.pop_back();

    //미포함
    recursive(idx + 1, order, subset, subsets);
}

void makeSubset(string& order, vector<string>& subsets) {
    string subset = "";
    sort(order.begin(), order.end());
    recursive(0, order, subset, subsets);
}

vector<string> findCandis(vector<string>& subsets, vector<int>& course) {
    vector<int> max_cnt(11, 0);    // 메뉴 개수가 i개인 코스의 최대 주문량
    vector<int> checked(11, 0);    // course로 지정된 단품 여부
    vector<string> ans;

    sort(subsets.begin(), subsets.end(), pred());

    // 1. 후보 별 최대 개수 찾기
    for (int i = 0; i < subsets.size(); i++) {
        for (int j = i + 1; j < subsets.size() + 1; j++) {
            if (j == subsets.size() || subsets[i].compare(subsets[j]) != 0) {
                int cnt = j - i, n = subsets[i].size();
                if (cnt >= 2) max_cnt[n] = max_cnt[n] > cnt ? max_cnt[n] : cnt;
                i = j;
            }
        }
    }

    // 2. 최대 주문량의 코스 찾기
    for (auto& e : course) checked[e] = 1;

    for (int i = 0; i < subsets.size(); i++) {
        for (int j = i + 1; j < subsets.size() + 1; j++) {
            if (j == subsets.size() || subsets[i].compare(subsets[j]) != 0) {
                int cnt = j - i, n = subsets[i].size();
                if (cnt == max_cnt[n] && checked[n])
                    ans.push_back(subsets[i]);
                i = j;
            }
        }
    }

    sort(ans.begin(), ans.end());

    return ans;

}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    vector<string> subsets; // 가능한 조합 집합

    // 1. 모든 가능한 조합 만들기
    for (auto& order : orders)
        makeSubset(order, subsets);

    // 2. 등록할 후보 찾기
    answer = findCandis(subsets, course);

    return answer;
}*/