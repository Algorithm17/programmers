#include <iostream>
#include <vector>

using namespace std;

int dp[501][501];

int solution(vector<vector<int> > triangle) {
    int answer = 0;

    for (int i = 0; i < triangle.size(); i++) {
        if (i == 0) { //자신의 위쪽이 존재하지 않는 경우
            dp[i][0] = triangle[i][0];
            if (answer < dp[i][0]) answer = dp[i][0];
            continue;
        }

        for (int j = 0; j < triangle[i].size(); j++) {
            if (j == 0) dp[i][j] = dp[i - 1][j] + triangle[i][j]; //자신의 위쪽의 왼쪽이 존재하지 않는 경우

            else if (j == triangle[i].size() - 1) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j]; //자신의 위쪽이 존재하지 않는 경우

            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j]; //모두 존재하는 경우

            if (answer < dp[i][j]) answer = dp[i][j];
        }
    }
    return answer;
}

int main() {
    vector<vector<int> > triangle;
    vector<int> v;

    v.push_back(7);
    triangle.push_back(v);
    v.clear();

    v.push_back(3);
    v.push_back(8);
    triangle.push_back(v);
    v.clear();

    v.push_back(8);
    v.push_back(1);
    v.push_back(0);
    triangle.push_back(v);
    v.clear();

    v.push_back(2);
    v.push_back(7);
    v.push_back(4);
    v.push_back(4);
    triangle.push_back(v);
    v.clear();

    v.push_back(4);
    v.push_back(5);
    v.push_back(2);
    v.push_back(6);
    v.push_back(5);
    triangle.push_back(v);
    v.clear();

    cout << solution(triangle);
}