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

		dp[b][a] = -1; //�������� ���� ǥ��
	}

	dp[1][1] = 1; //���� ��ǥ�� ����ĥ �� �ִ� ��ǥ�̹Ƿ� 1�̶� ǥ��

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (i == 1) { 
				if (dp[i][j] == -1) continue; //�ڽ��� ������ �������̰� ���� ��
				else if (dp[i][j - 1] == -1) continue; //i == 1�� ��ġ�� �ְ� �ڽ��� �ٷ� ���� ������ �������̰� ���� ��
				else if (dp[i][j - 1] == 0) continue; //i == 1�� ��ġ�� �ְ� �ڽ��� �ٷ� ���� ������ �� �� ���� �����̾��� ��
				else dp[i][j] = 1; //�� ��

				continue;
			}

			if (j == 1) {
				if (dp[i][j] == -1) continue; //�ڽ��� ������ �������̰� ���� ��
				else if (dp[i - 1][j] == -1) continue; //j == 1�� ��ġ�� �ְ� �ڽ��� �ٷ� ���� ������ �������̰� ���� ��
				else if (dp[i - 1][j] == 0) continue; //j == 1�� ��ġ�� �ְ� �ڽ��� �ٷ� ���� ������ �� �� ���� �����̾��� ��
				else dp[i][j] = 1; //�� ��

				continue;
			}

			if (dp[i - 1][j] == -1 && dp[i][j - 1] == -1) continue; //�ڽ��� ����, ���� ��� �������̰� ���� ��
			else if (dp[i][j] == -1) continue; //�ڽ��� ������ �������̰� ���� ��
			else if (dp[i - 1][j] == -1) dp[i][j] = dp[i][j - 1]; //���� ���� ������ �������̰� �ְ� ���� ������ �������̰� ���� ��
			else if (dp[i][j - 1] == -1) dp[i][j] = dp[i - 1][j]; //���� ���� ������ �������̰� �ְ� ���� ������ �������̰� ���� ��
			else dp[i][j] = ((dp[i - 1][j] % mod) + (dp[i][j - 1] % mod)) % mod; //���� ����, ���� ��� �������̰� ���� �� 
		}
	}

	int answer = dp[n][m]; //(n, m)���� �� �� �ִ� ����� ��
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