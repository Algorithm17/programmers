#include <iostream>
#include <string>

using namespace std;

int pow(int a, int b) {
    if (b == 0) return 1;
    else return a * pow(a, b - 1);
}

int solution(string dartResult) {
    int answer = 0;

    int score[3] = { 0, }; //세번의 점수 저장 배열

    int index = 0;

    for (int i = 0; i < dartResult.size(); i++) {
        if (dartResult[i] >= '0' && dartResult[i] <= '9') { //자신의 인덱스가 가리키는 값이 숫자인 경우
            if (i != 0) { //맨 처음 인덱스가 아닌 경우 자신의 바로 앞 인덱스가 숫자가 아니었다면 자신의 index 점수가 아닌 다음 index 점수로 계산해야하므로 index를 증가시켜줌
                if (dartResult[i - 1] < '0' || dartResult[i - 1] > '9') index++;
            }

            score[index] *= 10;

            score[index] = score[index] + (dartResult[i] - '0');

            continue;
        }

        else if (dartResult[i] == 'S') score[index] = pow(score[index], 1); //자신의 인덱스가 가리키는 값이 S 즉 싱글인 경우
        
        else if (dartResult[i] == 'D') score[index] = pow(score[index], 2); //자신의 인덱스가 가리키는 값이 D 즉 더블인 경우

        else if (dartResult[i] == 'T') score[index] = pow(score[index], 3); //자신의 인덱스가 가리키는 값이 T 즉 트리플인 경우

        else if (dartResult[i] == '*') { //자신의 인덱스가 가리키는 값이 * 즉 자신의 index와 index - 1의 값을 2배로 만들어주는 문자인 경우
            if (index == 0) score[index] *= 2;

            else {
                score[index] *= 2;
                score[index - 1] *= 2;
            }
        }

        else { //자신의 인덱스가 가리키는 값이 # 즉 자신의 index 값을 음수화하는 문자인 경우
            score[index] *= (-1);
        }
    }

    for (int i = 0; i < 3; i++) { //세 점수를 더한 값을 answer에 저장
        answer += score[i];
    }
    return answer; //answer 출력
}

int main() {
    string dartResult = "1S2D*3T";

    cout << solution(dartResult);
}

