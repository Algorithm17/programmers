#include <string>
#include <vector>

#define SHORTESTPATH 1000000007
using namespace std;
int dp[101][101];  // n, m (��, ��)

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    // ���� ��� ���� -1�� ����
    for(int i=0;i<puddles.size();i++){
        dp[puddles[i][1]][puddles[i][0]] = -1;
    }

    dp[1][1] = 1;
    // m : ��, n : ��
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            // ���� ��� ����
            if(dp[i][j] == -1) continue;
            // 1�� n��, n�� 1��
            // �ִ� ����� ���� (�ִ� ��ΰ� �ƴ�)
            if (i==1 && j==1) continue;
            else if(i==1) {
                if(dp[i][j-1] == -1) continue;
                // ���� ��� �����̴�.
                else if(dp[i][j-1] == 0) continue;
                // j-1 ������ �࿭���� ���� ���� ��, �״��� ��ĺ��ʹ� 0 (�̵��� �� ����.)
                // dp[1][4] == -1 �� �� dp[1][5] ~ dp[1][n] ������ 0 (���� �����ֱ� ����)
                dp[i][j] = 1;
                continue;
            }
            else if(j==1) {
                if(dp[i-1][j] == -1) continue;
                // ���� ��� �����̴�.
                else if(dp[i-1][j]==0) continue;
                // i-1 ������ �࿭���� ���� ���� ��, �״��� ��ĺ��ʹ� 0 (�̵��� �� ����.)
                // dp[4][1] == -1 �� �� dp[5][1] ~ dp[n][1] ������ 0 (���� �����ֱ� ����)
                dp[i][j] = 1;
                continue;
            }

            // �����ʰ� �Ʒ������� �����δ�.
            // ���� ������, �Ʒ����� ���� ��� �������� üũ�� ��
            // �� �� ���� ��� ������ �� �̵����� ���ϴ� �����̴�.
            // �ƴ϶�� �ִ� ����� ������ �� dp[i][j]�� �־��ش�.
            if(dp[i-1][j] == -1 && dp[i][j-1] == -1) continue;
            else if(dp[i-1][j] == -1) dp[i][j] = dp[i][j-1];
            else if(dp[i][j-1] == -1) dp[i][j] = dp[i-1][j];
            else dp[i][j] = (dp[i][j-1] + dp[i-1][j])%SHORTESTPATH;


        }
    }

    answer = dp[n][m];

    return answer;
}
