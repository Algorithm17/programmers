#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0; //모든 음식의 스코빌 지수를 K이상으로 만들기 위해 섞어야 하는 최소 횟수

    priority_queue<int> pq;

    for (int i = 0; i < scoville.size(); i++) {
        pq.push(-scoville[i]);
    }

    bool check = false; //모든 음식의 스코빌 지수를 K 이상으로 만들수 있는지 여부

    while (!pq.empty()) {
        int node = -pq.top(); //가장 맵지 않은 스코빌 지수
        
        pq.pop();

        if (node >= K) { //가장 맵지 않은 스코빌 지수가 K 이상인 경우 모든 음식의 스코빌 지수가 K 이상!
            check = true; 
            break;
        }

        if (pq.empty()) break;

        answer++; //가장 맵지 않은 음식의 스코빌 지수가 K 이상이 아닌 경우 한번 더 섞어야 하므로 answer를 1 증가시켜줌

        int nextnode = -pq.top(); //두 벚째로 맵지않은 음식의 스코빌 지수

        pq.pop();

        pq.push(-(node + 2 * nextnode)); //섞은 음식의 스코빌 지수를 우선순위 큐에 삽입
    }

    if (!check) answer = -1; //모든 음식의 스코빌 지수를 K 이상으로 만들 수 없는 경우 answer의 값으로 -1 저장

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> scoville;

    scoville.push_back(1);
    scoville.push_back(2);
    scoville.push_back(3);
    scoville.push_back(9);
    scoville.push_back(10);
    scoville.push_back(12);

    cout << solution(scoville, 7);
    return 0;
}