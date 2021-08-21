#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{

    bool operator()(vector<int> a, vector<int> b){
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    // jobs : 대기열
    int answer=0;
    int j=0;
    int time = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;

    while(!pq.empty() || j<jobs.size()){
        // 대기열들이 있는데, 현재 시간보다 작거나 같으며
        // 현재 j 번째가 jobs총 크기 보다 작다면
        if(j < jobs.size() && jobs[j][0] <= time ){
            // j가 jobs.size를 넘지 않는다면
            pq.push(jobs[j++]);
            continue;
        }

        if(!pq.empty()){
            time += pq.top()[1];
            // pq.top()[1] : 실행 시간
            answer += time - pq.top()[0];
            // 총 시간 - i 번째 도착 시간 (pq.top()[0])

            pq.pop();
        }
        else{
            // 큐에 더이상 데이터가 없을 때, 다음 번 대기 열의 시작 점으로 이동한다.
            time = jobs[j][0];
        }
    }

    return answer/jobs.size();

}
