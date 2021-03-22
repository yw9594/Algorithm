/*#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N;
    long long int answer = 0LL;
    vector<long long int> stk;

    freopen("input.txt", "r", stdin);
    std::istream::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    while (N--) {
        long long int num;
        cin >> num;

        if (num != 0)
            stk.push_back(num);
        else
            stk.pop_back();
    }

    while (!stk.empty()) {
        answer += stk.back();
        stk.pop_back();
    }
    cout << answer;

    return 0;
}*/