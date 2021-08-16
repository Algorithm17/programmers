#include <iostream>
#include <vector>

using namespace std;

int answer;

void dfs(vector<int> numbers, int target, int ind, int sum) {
    if (ind == numbers.size()) { //ind�� numbers�� ����� ���� ��
        if (sum == target) answer++; //�հ� ���� target�� ���� �� answer�� ����������

        return;
    }

    dfs(numbers, target, ind + 1, sum + numbers[ind]); //+���� ����
    dfs(numbers, target, ind + 1, sum - numbers[ind]); //-���� ����
}

int solution(vector<int> numbers, int target) {

    dfs(numbers, target, 0, 0); //dfs����

    return answer; //answer��(���� target�� ����� ��� ����) ��ȯ
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