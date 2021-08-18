#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

#define DECIMALLARGEST 10000000

bool decimal[DECIMALLARGEST];
bool check_arr[DECIMALLARGEST];
bool visited[10];
int answer;

// 2 ~ 루트 n까지 반복문을 수행하여 각 숫자로 나누어지는 파악한다.
bool decimalcheck(int n){
    if(n<=1) return false;

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int arr[7];

void backtracking(string numbers,int num, int cnt, int len){
    // numbers, 현재 숫자, 횟수, 문자열 길이 제한

    arr[cnt] = num;

    if(cnt==len){
        // 문자열을 이제 숫자로 바꾼다.
        int result = 0;
        for(int i=1;i<=len;i++){
            result += pow(10,len-i) * arr[i];
        }

        if(check_arr[result]) return;
        if(!decimalcheck(result)) return;
        check_arr[result] = true;
        answer++;
        return;
    }

    for(int i=0;i<numbers.size();i++){
        if(visited[i]) continue;
        visited[i] = true;
        backtracking(numbers,numbers[i] - '0',cnt+1,len);
        visited[i] = false;
    }
}

int solution(string numbers) {


    for(int i=1;i<=numbers.size();i++){
        for(int j=0; j< numbers.size();j++){
            if(visited[j]) continue;
            visited[j] = true;
            backtracking(numbers,numbers[j]-'0',1,i); // 문자열, 문자열 숫자로, 0개, 숫자 길이
            visited[j] = false;
        }

        fill(visited,visited + 9,false);
        // 백트로킹 구역 초기화
    }




    return answer;
}


int main(){



    cout << solution("011") << "\n";
    answer = 0;
    cout << solution("17") << "\n";



    return 0;


}
