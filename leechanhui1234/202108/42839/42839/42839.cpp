#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
bool check[10000000];
vector<int> v;

bool checkprime(int n) { //소수인지 판별 
    if (n <= 1) return false; //1 or 0은 무조건 소수 아니니 false 반환

    for (int i = 2; i <= sqrt(n); i++) { //2 ~ 루트 n으로 나눠지는지 판단
        if (n % i == 0) return false; //나눠지면 소수 아님 false 반환
    }

    return true; //안나눠지는 경우 true 반환
}

int pow(int a, int b) { //a ^ b
    if (b == 0) return 1;
    return a * pow(a, b - 1);
}

int arr[10];
bool visit[10];
int answer;

void backtracking(string numbers, int data, int ind, int len) {
    arr[ind] = data; 

    if (ind == len) {
        int number = 0; //number에 arr에 저장되어 있는 한자리 데이터 len자리로 변환하여 저장
        for (int i = 1; i <= len; i++){
            number = number + pow(10, len - i) * arr[i];
        }

        if (check[number]) return; //이 number를 이미 check해본 경우 continue
        if (checkprime(number)) { //소수인지 판별(소수인 경우)
            answer++; //answer값 증가시킴
        }

        check[number] = true; //체크했다고 표시

        return;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (visit[i]) continue; //이미 방문한 경우 continue

        visit[i] = true; //방문했다고 표시
        backtracking(numbers, numbers[i] - '0', ind + 1, len); //다음 수로부터 백트래킹 수행
        visit[i] = false; //방문했다는 표시 없앰
    }
}

int solution(string numbers) {

    for (int i = 1; i <= numbers.size(); i++) { //길이가 i인 소수
        for (int j = 0; j < numbers.size(); j++) { //백트래킹 돌릴 index
            if (visit[j]) continue; //이미 방문한 경우 continue
            visit[j] = true; 
            backtracking(numbers, numbers[j] - '0', 1, i); //백트래킹 수행
            visit[j] = false;
        }

        fill(visit, visit + 9, false);
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cout << solution("011");
    return 0;
}