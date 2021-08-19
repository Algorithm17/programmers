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
    // unordered_set : set과 비슷하나, 정렬이 자동으로 되지 않는다.
    dp[0].insert(N);

    // 최소값은 1 ~ 7까지이다.
    for(int k=1;k<8;k++){
        for(int i=0;i<k;i++){
            for(int j=0; j<k;j++){
                // (i + j + 1)개 == k개 구간
                if(i+j+1 != k) continue;

                // dp[i][0]부터 확인
                for(int a : dp[i]){
                    // dp[j][0]부터 확인
                    for(int b: dp[j]){
                        // dp[k]자리에 삽입한다.
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
        // NNN ~ 을 삽입한다.
        dp[k].insert(getNN(N,k));

        if(dp[k].count(number))
        // 지정한 number 키와 일치하는 데이터를 찾는다.
            return k+1;
    }

    return -1;
}


int main(){

    cout << solution(5,12);

    return 0;

}
