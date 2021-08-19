#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

int getNN(int N, int len){
    int data = N;

    for(int i=1;i<=len;i++){
        data = data * 10 + N;
    }

    return data;
}

int solution(int N, int number) {
    if(N == number) return 1;

    vector<unordered_set<int>> dp(8);
    // unordered_set : set�� ����ϳ�, ������ �ڵ����� ���� �ʴ´�.
    dp[0].insert(N);

    // �ּҰ��� 1 ~ 7�����̴�.
    for(int k=1;k<8;k++){
        for(int i=0;i<k;i++){
            for(int j=0; j<k;j++){
                // (i + j + 1)�� == k�� ����
                if(i+j+1 != k) continue;

                // dp[i][0]���� Ȯ��
                for(int a : dp[i]){
                    // dp[j][0]���� Ȯ��
                    for(int b: dp[j]){
                        // dp[k]�ڸ��� �����Ѵ�.
                        // +, -, x, /
                        dp[k].insert(a+b);
                        if(a-b>0)
                            dp[k].insert(a-b);
                        dp[k].insert(a*b);
                        if(a/b>0)
                            dp[k].insert(a/b);
                    }
                }
            }
        }
        // NNN ~ �� �����Ѵ�.
        dp[k].insert(getNN(N,k));

        if(dp[k].count(number))
        // ������ number Ű�� ��ġ�ϴ� �����͸� ã�´�.
            return k+1;
    }

    return -1;
}


int main(){

    cout << solution(5,12);

    return 0;

}
