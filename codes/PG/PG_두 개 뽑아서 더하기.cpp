/*#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    vector<int> arr;

    int N = numbers.size();
    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
            arr.push_back(numbers[i] + numbers[j]);

    sort(arr.begin(), arr.end());

    int i = 0, j = i + 1;
    int M = arr.size();
    while (j <= M) {
        if (j == M || arr[i] != arr[j]) {
            answer.push_back(arr[i]);
            i = j;
            j = i + 1;
        }
        else j++;
    }

    return answer;
}*/