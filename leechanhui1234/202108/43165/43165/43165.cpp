#include <iostream>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> numbers, int target, int ind, int sum) {
    if (ind == numbers.size()) { //ind와 numbers의 사이즈가 같을 때
        if (sum == target) answer++; //합과 숫자 target이 같을 시 answer를 증가시켜줌

        return;
    }

    dfs(numbers, target, ind + 1, sum + numbers[ind]); //+연산 수행
    dfs(numbers, target, ind + 1, sum - numbers[ind]); //-연산 수행
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0); //dfs수행

    return answer; //answer값(숫자 target을 만드는 방법 개수) 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    cout << solution(v, 3);

    return 0;
}