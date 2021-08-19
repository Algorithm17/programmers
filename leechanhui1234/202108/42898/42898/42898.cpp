#include <iostream>
#include <string>
#include <vector>
#define mod 1000000007

using namespace std;

int dp[101][101];

int solution(int m, int n, vector<vector<int > > puddles) {

	int i, j;

	for (i = 0; i < puddles.size(); i++) {

		int a = puddles[i][0], b = puddles[i][1];

		dp[b][a] = -1; //물웅덩이 지역 표시
	}

	dp[1][1] = 1; //집의 좌표는 지나칠 수 있는 좌표이므로 1이라 표시

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (i == 1) { 
				if (dp[i][j] == -1) continue; //자신의 지역에 물웅덩이가 있을 때
				else if (dp[i][j - 1] == -1) continue; //i == 1의 위치에 있고 자신의 바로 왼쪽 지역에 물웅덩이가 있을 때
				else if (dp[i][j - 1] == 0) continue; //i == 1의 위치에 있고 자신의 바로 왼쪽 지역이 갈 수 없는 지역이었을 때
				else dp[i][j] = 1; //그 외

				continue;
			}

			if (j == 1) {
				if (dp[i][j] == -1) continue; //자신의 지역에 물웅덩이가 있을 때
				else if (dp[i - 1][j] == -1) continue; //j == 1의 위치에 있고 자신의 바로 위쪽 지역에 물웅덩이가 있을 때
				else if (dp[i - 1][j] == 0) continue; //j == 1의 위치에 있고 자신의 바로 위쪽 지역이 갈 수 없는 지역이었을 때
				else dp[i][j] = 1; //그 외

				continue;
			}

			if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) continue; //자신의 왼쪽, 위쪽 모두 물웅덩이가 있을 때
			else if (dp[i][j] == -1) continue; //자신의 지역에 물웅덩이가 있을 때
			else if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1]; //나의 위쪽 지역은 물웅덩이가 있고 왼쪽 지역은 물웅덩이가 없을 때
			else if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j]; //나의 왼쪽 지역은 물웅덩이가 있고 위쪽 지역은 물웅덩이가 없을 때
			else dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod; //나의 위쪽, 왼쪽 모두 물웅덩이가 없을 때 
		}
	}

	int answer = dp[n][m]; //(n, m)까지 갈 수 있는 경우의 수
	return answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<vector<int> > puddles;

	vector<int> v;

	v.push_back(2);
	v.push_back(2);

	puddles.push_back(v);

	cout << solution(4, 3, puddles);

	return 0;
}