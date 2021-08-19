#include <string>
#include <vector>

#define SHORTESTPATH 1000000007
using namespace std;
int dp[101][101];  // n, m (행, 열)

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // 물이 잠긴 지역 -1로 저장
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    dp[1][1] = 1;
    // m : 열, n : 행
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // 물이 잠긴 지역
            if(dp[i][j] == -1) continue;
            // 1행 n열, n행 1열
            // 최단 경로의 개수 (최단 경로가 아닌)
            if (i==1 && j==1) continue;
            else if(i==1) {
                if(dp[i][j-1] == -1) continue;
                // 물에 잠긴 지역이다.
                else if(dp[i][j-1] == 0) continue;
                // j-1 이전에 행열에서 물이 있을 때, 그다음 행렬부터는 0 (이동할 수 없다.)
                // dp[1][4] == -1 일 때 dp[1][5] ~ dp[1][n] 까지는 0 (물로 막혀있기 때문)
                dp[i][j] = 1;
                continue;
            }
            else if(j==1) {
                if(dp[i-1][j] == -1) continue;
                // 물에 잠긴 지역이다.
                else if(dp[i-1][j]==0) continue;
                // i-1 이전에 행열에서 물이 있을 때, 그다음 행렬부터는 0 (이동할 수 없다.)
                // dp[4][1] == -1 일 때 dp[5][1] ~ dp[n][1] 까지는 0 (물로 막혀있기 때문)
                dp[i][j] = 1;
                continue;
            }

            // 오른쪽과 아래쪽으로 움직인다.
            // 이전 오른쪽, 아래쪽이 물에 잠긴 지역인지 체크한 후
            // 둘 다 물에 잠긴 지역일 시 이동하지 못하는 영역이다.
            // 아니라면 최단 경로의 개수를 현 dp[i][j]에 넣어준다.
            if(dp[i-1][j] == -1 && dp[i][j-1] == -1) continue;
            else if(dp[i-1][j] == -1) dp[i][j] = dp[i][j-1];
            else if(dp[i][j-1] == -1) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%SHORTESTPATH;


        }
    }

    answer = dp[n][m];

    return answer;
}
