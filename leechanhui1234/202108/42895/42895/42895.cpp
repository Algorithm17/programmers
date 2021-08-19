#include <iostream>
#include <vector>

using namespace std;

vector<int> num[9];

int ind[9];

int ans[32001];

int solution(int N, int number) {
    int n = N;
    num[1].push_back(N); //n = 1�� ������ ����
    ans[n] = 1; //N�� N�� �� �ѹ��� ���Ǿ��� ������ 1����

    for (int i = 2; i <= 8; i++) {
        n = n * 10 + N; //N, NN, NNN���� ����

        num[i].push_back(n); //�� n���� num[i](N�� i�� ���)�� ����

        if (n <= 32001) ans[n] = i; //n���Ƚ�� ����

        for (int j = 1; j <= i - 1; j++) {
            int data1 = j; //N�� j�� ���
            int data2 = i - j; //N�� i - j�� ���
            
            for (int k = 0; k < num[data1].size(); k++) { //N�� j�� ����� �������� �������� ���� �ݺ��� ����
                for (int kk = 0; kk < num[data2].size(); kk++) { //N�� i - j�� ����� �������� �������� ���� �ݺ��� ����
                    int number1 = num[data1][k];
                    int number2 = num[data2][kk];

                    if (number1 >= 32001 || number2 >= 32001) continue; //������ 32000�� ������ ���Ƹ� �ʿ䰡 ���� ������ continue

                    if (number1 + number2 <= 32000) { //���� ������ �ʰ����� ���� ��
                        if (ans[number1 + number2] == 0) num[i].push_back(number1 + number2);
                        if (ans[number1 + number2] == 0) ans[number1 + number2] = i;
                    }

                    if (number1 - number2 >= 0) { //���� ������ �ƴ� ��
                        if (ans[number1 - number2] == 0) num[i].push_back(number1 - number2);
                        if (ans[number1 - number2] == 0) ans[number1 - number2] = i;
                    }

                    if (number1 * number2 <= 32000) { //���� ������ �ʰ����� ���� ��
                        if (ans[number1 * number2] == 0) num[i].push_back(number1 * number2);
                        if (ans[number1 * number2] == 0) ans[number1 * number2] = i;
                    }

                    if (number2 == 0) continue; //0���δ� �� �����Ƿ� continue

                    if (number1 % number2 == 0) { //0���� ������ ������ ��
                        if (ans[number1 / number2] == 0) num[i].push_back(number1 / number2);

                        if (ans[number1 / number2] == 0) ans[number1 / number2] = i;
                    }
                }
            }
        }
    }
    if (ans[number] != 0) return ans[number]; //ans�� 0�� �ƴ� ��� N�� 8�� ���Ϸ� ���� ���̹Ƿ� ans��(N ���Ƚ��) �� ����
    else return -1; //ans�� 0�� ��� N�� 8�� �ʰ��� ���Ǿ�� �ϴ� �������̹Ƿ� -1����
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(5, 12) << endl;
    cout << solution(5, 31168);
    return 0;
}