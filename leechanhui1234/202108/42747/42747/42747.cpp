#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> v;

void binary(int start, int end) {
    int mid = (start + end) / 2; //start와 end의 중앙값

    int cnt = 0; //h편 이상 인용된 논문의 수
    int cnt2 = 0; //h편 이하 인용된 논문의 수

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= mid) cnt++;
    }

    cnt2 = v.size() - cnt;

    bool check = false; //H - index 조건에 만족하는지 여부

    if (cnt >= mid && cnt2 <= mid) { //만족할 경우
        check = true;
        if (ans < mid) ans = mid; //ans 업데이트
    }

    if (start == end) return; //start == end인 경우 return

    if (check) binary(mid + 1, end); //H - index 조건에 만족하는 경우 
    else binary(start, mid); //H - index 조건에 만족하지 않는 경우
}

int solution(vector<int> citations) {
    int ma = 0; //논문인용수의 최댓값 찾기
    for (int i = 0; i < citations.size(); i++) {
        if (ma < citations[i]) ma = citations[i];
        v.push_back(citations[i]);
    }

    binary(0, ma); //최솟값을 0, 최댓값을 ma로 두고 이분탐색돌림

    int answer = ans; //answer 업데이트
    return answer;
}

int main() {
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << solution(citations);
}