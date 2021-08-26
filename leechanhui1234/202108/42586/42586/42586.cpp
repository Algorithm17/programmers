#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int work[101] = { 0, }; //������ �� �� �� �̷�������� ����

    for (int i = 0; i < progresses.size(); i++) { //������ ���
        work[i] = (100 - progresses[i]) / speeds[i];

        if ((100 - progresses[i]) % speeds[i] != 0) work[i] += 1;
    }

    int ans = 0; //��� ����� �����Ǵ��� ����
    int ma = -1; //�ִ�

    for (int i = 0; i < progresses.size(); i++) {
        if (i == 0) { //i == 0�� ��� �ڱ��ڽ��� ����� ���� �����ǰ� ����
            ans++;
            ma = work[i];
            continue;
        }

        if (ma >= work[i]) { //�ִ񰪺��� �������� ������� ��ɵ� ���� ���� ����
            ans++;
            continue;
        }

        else { //�׷��� ���� ��� ��ɵ� �տ��Ͱ� ���� ���� �Ұ�
            answer.push_back(ans);
            ans = 1;
            ma = work[i];
            continue;
        }
    }

    answer.push_back(ans);
    return answer;
}

int main() {
    vector<int> progresses;
    vector<int> speeds;

    progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);

    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);

    vector<int> v = solution(progresses, speeds);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}