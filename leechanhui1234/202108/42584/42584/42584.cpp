#include <iostream>
#include <string>
#include <vector>

using namespace std;

int top = -1; //���� ���� ������ top��ġ
int top1 = -1; //�ε��� ���� ������ top��ġ

int stack[100001];
int stackindex[100001];

void push(int n) { //������ ���ÿ� ����
    stack[++top] = n;
}

void indexpush(int n) { //�ε����� ���ÿ� ����
    stackindex[++top1] = n;
}

int pop() { //������ ���ÿ��� ����
    return stack[top--];
}

int pop1() { //�ε����� ���ÿ��� ����
    return stackindex[top1--];
}

int ss() { //������ �� ���� �ִ� ������ Ȯ��
    return stack[top];
}

int result[100001]; //������ �������� �ʴ� �Ⱓ ���� �迭

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    push(prices[0]); //�ε��� 0�� ���� ���ÿ� ����
    indexpush(0); //�ε��� 0 ��ü�� ���ÿ� ����

    for (int i = 1; i < prices.size(); i++) {
        if (ss() > prices[i]) { //���� �� ���� �ִ� ���ݺ��� i�� ����Ű�� �ε����� ������ �� ���� ���
            while (1) {
                if (ss() <= prices[i]) break; //���� �� ���� �ִ� ���ݺ��� i�� ����Ű�� �ε����� ������ �� ū ��� break 
                int n = pop(); //���� �� ���� �ִ� ����
                int index = pop1(); //�� ������ �ε���

                result[index] = i - index; //index�� ������ �� �� ���� �������� �ʴ��� ����
            }
        }

        if (i != prices.size() - 1) { //i�� �� ������ �ε����� �ƴ� ���
            push(prices[i]); //�� �ε����� ���� ������ ���ÿ� ����
            indexpush(i); //�ε����� ���ÿ� ����
        }
    }

    while (top != -1) { //������ ������� ���� ��� �ϳ��ϳ� ������ �� index�� ���� ������ �� �� ���� �������� �ʴ��� ����
        int n = pop(); 
        int index = pop1();

        result[index] = prices.size() - 1 - index;
    }

    for (int i = 0; i < prices.size(); i++) { //answer���Ϳ� result�� ����ִ� ���� �� �ű�
        answer.push_back(result[i]);
    }
    return answer;
}

int main() {
    vector<int> prices;

    prices.push_back(1);
    prices.push_back(2);
    prices.push_back(3);
    prices.push_back(2);
    prices.push_back(3);

    vector<int> v = solution(prices);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }

}