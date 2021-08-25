#include <iostream>
#include <string>
#include <vector>

using namespace std;

int top = -1; //가격 저장 스택의 top위치
int top1 = -1; //인덱스 저장 스택의 top위치

int stack[100001];
int stackindex[100001];

void push(int n) { //가격을 스택에 저장
    stack[++top] = n;
}

void indexpush(int n) { //인덱스를 스택에 저장
    stackindex[++top1] = n;
}

int pop() { //가격을 스택에서 꺼냄
    return stack[top--];
}

int pop1() { //인덱스를 스택에서 꺼냄
    return stackindex[top1--];
}

int ss() { //스택의 맨 위에 있는 가격을 확인
    return stack[top];
}

int result[100001]; //가격이 떨어지지 않는 기간 저장 배열

vector<int> solution(vector<int> prices) {
    vector<int> answer;

    push(prices[0]); //인덱스 0의 가격 스택에 저장
    indexpush(0); //인덱스 0 자체를 스택에 저장

    for (int i = 1; i < prices.size(); i++) {
        if (ss() > prices[i]) { //스택 맨 위에 있는 가격보다 i가 가리키는 인덱스의 가격이 더 작은 경우
            while (1) {
                if (ss() <= prices[i]) break; //스택 맨 위에 있는 가격보다 i가 가리키는 인덱스의 가격이 더 큰 경우 break 
                int n = pop(); //스택 맨 위에 있는 가격
                int index = pop1(); //그 가격의 인덱스

                result[index] = i - index; //index의 가격이 몇 초 동안 떨어지지 않는지 저장
            }
        }

        if (i != prices.size() - 1) { //i가 맨 마지막 인덱스가 아닌 경우
            push(prices[i]); //그 인덱스에 대한 가격을 스택에 삽입
            indexpush(i); //인덱스를 스택에 삽입
        }
    }

    while (top != -1) { //스택이 비어있지 않은 경우 하나하나 꺼내어 그 index에 대한 가격이 몇 초 동안 떨어지지 않는지 저장
        int n = pop(); 
        int index = pop1();

        result[index] = prices.size() - 1 - index;
    }

    for (int i = 0; i < prices.size(); i++) { //answer벡터에 result에 들어있는 값들 다 옮김
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