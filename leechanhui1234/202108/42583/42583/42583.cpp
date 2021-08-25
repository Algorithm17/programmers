#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;

    int time = 0;

    queue<int> cross; // �ǳʴ� Ʈ�� 
    queue<int> t; // �ٸ����� �ӹ����� �ð� 
    queue<int> daegi; //����ϴ� Ʈ��
    queue<int> complete; //�Ϸ� Ʈ��

    for (int i = 0; i < truck_weights.size(); i++) { //���Ʈ���� Ʈ���� ����
        daegi.push(truck_weights[i]);
    }

    int sum = 0; //Ʈ�� ������ �� ��

    for (time = 1; ; time++) {

        int tim;

        if (!t.empty()) { //�ٸ����� �ӹ����� �ð� ť�� ���� �ʾ��� ���
            tim = t.front(); //�ð� Ȯ��
        }

        if (tim == bridge_length) { //�ٸ� ���̿� �ӹ����� �ð��� ������ ���
            t.pop(); //t�� queue���� ����

            int truck = cross.front(); //�ٸ� �ǳʴ� Ʈ�� ����

            cross.pop();

            sum -= truck; // �� Ʈ�� ���Կ��� �ٸ� �ǳʴ� Ʈ�� ���� ��

            complete.push(truck); //Ʈ���� �Ϸ� Ʈ���� ����
        }

        if (!t.empty()) { //t�� ���� �ʾ��� ���

            for (int i = 0; i < t.size(); i++) { //�ϳ��ϳ� �ð����� 1�߰���Ŵ
                int ti = t.front();

                t.pop();

                t.push(ti + 1);

            }

        }

        if (daegi.empty() && cross.empty()) break; //����ϴ� Ʈ����, �ǳʴ� Ʈ���� ���� �� break

        int truck = -1;

        if (!daegi.empty()) { //����ϴ� Ʈ���� ���� �ʾ��� ���
            truck = daegi.front(); //��� ť���� Ʈ�� �ϳ��� ����
        }

        if (sum + truck <= weight && truck != -1) { //��� Ʈ���� �����ϰ� �ٸ��� Ʈ�� ���Ը� �ߵ� �� ���� ��
            daegi.pop(); //��� ť���� ���� ����
            cross.push(truck); //�ٸ� �ǳʴ� ť�� Ʈ���� �ű�
            t.push(1); //�� �ð��� 1�� ����
            sum += truck; //�ٸ� ���� �ִ� Ʈ���� �տ� �� Ʈ���� ����
        }
    }

    answer = time; //�ð��� answer������ ������Ʈ
    return answer;
}

int main() {
    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);
    cout << solution(2, 10, truck_weights);
}