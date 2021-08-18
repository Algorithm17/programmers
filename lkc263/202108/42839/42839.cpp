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

// 2 ~ ��Ʈ n���� �ݺ����� �����Ͽ� �� ���ڷ� ���������� �ľ��Ѵ�.
bool decimalcheck(int n){
    if(n<=1) return false;

    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;
    }
    return true;
}

int arr[7];

void backtracking(string numbers,int num, int cnt, int len){
    // numbers, ���� ����, Ƚ��, ���ڿ� ���� ����

    arr[cnt] = num;

    if(cnt==len){
        // ���ڿ��� ���� ���ڷ� �ٲ۴�.
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
            backtracking(numbers,numbers[j]-'0',1,i); // ���ڿ�, ���ڿ� ���ڷ�, 0��, ���� ����
            visited[j] = false;
        }

        fill(visited,visited + 9,false);
        // ��Ʈ��ŷ ���� �ʱ�ȭ
    }




    return answer;
}


int main(){



    cout << solution("011") << "\n";
    answer = 0;
    cout << solution("17") << "\n";



    return 0;


}
