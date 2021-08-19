#include <iostream>
#include <vector>

using namespace std;

vector<int> num[9];

int ind[9];

int ans[32001];

int solution(int N, int number) {
    int n = N;
    num[1].push_back(N); //n = 1인 정수들 저장
    ans[n] = 1; //N은 N이 단 한번만 사용되었기 때문에 1저장

    for (int i = 2; i <= 8; i++) {
        n = n * 10 + N; //N, NN, NNN등을 만듦

        num[i].push_back(n); //이 n값을 num[i](N을 i번 사용)에 삽입

        if (n <= 32001) ans[n] = i; //n사용횟수 저장

        for (int j = 1; j <= i - 1; j++) {
            int data1 = j; //N을 j번 사용
            int data2 = i - j; //N을 i - j번 사용
            
            for (int k = 0; k < num[data1].size(); k++) { //N을 j번 사용한 정수들을 가져오기 위해 반복문 돌림
                for (int kk = 0; kk < num[data2].size(); kk++) { //N을 i - j번 사용한 정수들을 가져오기 위해 반복문 돌림
                    int number1 = num[data1][k];
                    int number2 = num[data2][kk];

                    if (number1 >= 32001 || number2 >= 32001) continue; //정수가 32000을 넘으면 세아릴 필요가 없기 때문에 continue

                    if (number1 + number2 <= 32000) { //합이 범위를 초과하지 않을 때
                        if (ans[number1 + number2] == 0) num[i].push_back(number1 + number2);
                        if (ans[number1 + number2] == 0) ans[number1 + number2] = i;
                    }

                    if (number1 - number2 >= 0) { //차가 음수가 아닐 때
                        if (ans[number1 - number2] == 0) num[i].push_back(number1 - number2);
                        if (ans[number1 - number2] == 0) ans[number1 - number2] = i;
                    }

                    if (number1 * number2 <= 32000) { //곱이 범위를 초과하지 않을 때
                        if (ans[number1 * number2] == 0) num[i].push_back(number1 * number2);
                        if (ans[number1 * number2] == 0) ans[number1 * number2] = i;
                    }

                    if (number2 == 0) continue; //0으로는 못 나누므로 continue

                    if (number1 % number2 == 0) { //0으로 나누어 떨어질 때
                        if (ans[number1 / number2] == 0) num[i].push_back(number1 / number2);

                        if (ans[number1 / number2] == 0) ans[number1 / number2] = i;
                    }
                }
            }
        }
    }
    if (ans[number] != 0) return ans[number]; //ans가 0이 아닐 경우 N이 8번 이하로 사용된 것이므로 ans값(N 사용횟수) 을 리턴
    else return -1; //ans가 0일 경우 N이 8번 초과로 사용되어야 하는 정수들이므로 -1리턴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << solution(5, 12) << endl;
    cout << solution(5, 31168);
    return 0;
}