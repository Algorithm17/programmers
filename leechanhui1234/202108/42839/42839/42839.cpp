#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;
bool check[10000000];
vector<int> v;

bool checkprime(int n) { //�Ҽ����� �Ǻ� 
    if (n <= 1) return false; //1 or 0�� ������ �Ҽ� �ƴϴ� false ��ȯ

    for (int i = 2; i <= sqrt(n); i++) { //2 ~ ��Ʈ n���� ���������� �Ǵ�
        if (n % i == 0) return false; //�������� �Ҽ� �ƴ� false ��ȯ
    }

    return true; //�ȳ������� ��� true ��ȯ
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
        int number = 0; //number�� arr�� ����Ǿ� �ִ� ���ڸ� ������ len�ڸ��� ��ȯ�Ͽ� ����
        for (int i = 1; i <= len; i++){
            number = number + pow(10, len - i) * arr[i];
        }

        if (check[number]) return; //�� number�� �̹� check�غ� ��� continue
        if (checkprime(number)) { //�Ҽ����� �Ǻ�(�Ҽ��� ���)
            answer++; //answer�� ������Ŵ
        }

        check[number] = true; //üũ�ߴٰ� ǥ��

        return;
    }

    for (int i = 0; i < numbers.size(); i++) {
        if (visit[i]) continue; //�̹� �湮�� ��� continue

        visit[i] = true; //�湮�ߴٰ� ǥ��
        backtracking(numbers, numbers[i] - '0', ind + 1, len); //���� ���κ��� ��Ʈ��ŷ ����
        visit[i] = false; //�湮�ߴٴ� ǥ�� ����
    }
}

int solution(string numbers) {

    for (int i = 1; i <= numbers.size(); i++) { //���̰� i�� �Ҽ�
        for (int j = 0; j < numbers.size(); j++) { //��Ʈ��ŷ ���� index
            if (visit[j]) continue; //�̹� �湮�� ��� continue
            visit[j] = true; 
            backtracking(numbers, numbers[j] - '0', 1, i); //��Ʈ��ŷ ����
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