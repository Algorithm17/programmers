#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0; //��� ������ ���ں� ������ K�̻����� ����� ���� ����� �ϴ� �ּ� Ƚ��

    priority_queue<int> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }

    bool check = false; //��� ������ ���ں� ������ K �̻����� ����� �ִ��� ����

    while (!pq.empty()) {
        int node = -pq.top(); //���� ���� ���� ���ں� ����
        
        pq.pop();

        if (node >= K) { //���� ���� ���� ���ں� ������ K �̻��� ��� ��� ������ ���ں� ������ K �̻�!
            check = true; 
            break;
        }

        if (pq.empty()) break;

        answer++; //���� ���� ���� ������ ���ں� ������ K �̻��� �ƴ� ��� �ѹ� �� ����� �ϹǷ� answer�� 1 ����������

        int nextnode = -pq.top(); //�� ��°�� �������� ������ ���ں� ����

        pq.pop();

        pq.push(-(node + 2 * nextnode)); //���� ������ ���ں� ������ �켱���� ť�� ����
    }

    if (!check) answer = -1; //��� ������ ���ں� ������ K �̻����� ���� �� ���� ��� answer�� ������ -1 ����

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> scoville;

    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    cout << solution(scoville, 7);
    return 0;
}