#include <iostream>
#include <string>

using namespace std;

int pow(int a, int b) {
    if (b == 0) return 1;
    else return a * pow(a, b - 1);
}

int solution(string dartResult) {
    int answer = 0;

    int score[3] = { 0, }; //������ ���� ���� �迭

    int index = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') { //�ڽ��� �ε����� ����Ű�� ���� ������ ���
            if (i != 0) { //�� ó�� �ε����� �ƴ� ��� �ڽ��� �ٷ� �� �ε����� ���ڰ� �ƴϾ��ٸ� �ڽ��� index ������ �ƴ� ���� index ������ ����ؾ��ϹǷ� index�� ����������
                if (dartResult[i - 1] < '0' || dartResult[i - 1] > '9') index++;
            }

            score[index] *= 10;

            score[index] = score[index] + (dartResult[i] - '0');

            continue;
        }

        else if (dartResult[i] == 'S') score[index] = pow(score[index], 1); //�ڽ��� �ε����� ����Ű�� ���� S �� �̱��� ���
        
        else if (dartResult[i] == 'D') score[index] = pow(score[index], 2); //�ڽ��� �ε����� ����Ű�� ���� D �� ������ ���

        else if (dartResult[i] == 'T') score[index] = pow(score[index], 3); //�ڽ��� �ε����� ����Ű�� ���� T �� Ʈ������ ���

        else if (dartResult[i] == '*') { //�ڽ��� �ε����� ����Ű�� ���� * �� �ڽ��� index�� index - 1�� ���� 2��� ������ִ� ������ ���
            if (index == 0) score[index] *= 2;

            else {
                score[index] *= 2;
                score[index - 1] *= 2;
            }
        }

        else { //�ڽ��� �ε����� ����Ű�� ���� # �� �ڽ��� index ���� ����ȭ�ϴ� ������ ���
            score[index] *= (-1);
        }
    }

    for (int i = 0; i < 3; i++) { //�� ������ ���� ���� answer�� ����
        answer += score[i];
    }
    return answer; //answer ���
}

int main() {
    string dartResult = "1S2D*3T";

    cout << solution(dartResult);
}

