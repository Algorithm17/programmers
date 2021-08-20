#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Disk {
    int arrive; //도착시간
    int burst; //실행시간
    int index; //자신의 원래 인덱스
};

Disk j[501];

bool visit[501]; //방문했는지 여부

int ans[501]; //작업 요청으로부터 종료까지 걸린 시간

bool cmd(Disk a, Disk b) { 
    if (a.arrive > b.arrive) return false;
    else if (a.arrive < b.arrive) return true;
    else {
        if (a.burst > b.burst) return false;
        else return true;
    }
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    for (int i = 0; i < jobs.size(); i++) {
        int first = jobs[i][0];
        int second = jobs[i][1];

        j[i].arrive = first;
        j[i].burst = second;
        j[i].index = i;
    }

    sort(j, j + jobs.size(), cmd);

    priority_queue < pair<int, pair<int, int> > > pq;

    int str = j[0].arrive;

    for (int i = 0; i < jobs.size(); i++) {
        if (str == j[i].arrive) { //디스크들 중 도착시간이 가장 빠른 경우
            pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index)));
        }
    }

    int sum = 0; //총 진행시간

    while (!pq.empty()) {
        int nodeburst = -pq.top().first;
        int nodearrive = -pq.top().second.first;
        int nodeindex = -pq.top().second.second;

        pq.pop();

        if (visit[nodeindex]) continue; //노드 인덱스를 방문한 적이 있는지 여부

        visit[nodeindex] = true; 

        if (sum <= nodearrive) { //총 진행시간이 도착시간보다 작거나 같은 경우
            ans[nodeindex] = nodeburst; //요청부터 종료까지 걸린 시간은 실행시간만큼만 소요
            sum = nodearrive + nodeburst; //총 진행시간을 도착시간 + 실행시간으로 업뎃
        }

        else { //총 진행시간이 도착시간보다 큰 경우
            ans[nodeindex] = sum - nodearrive + nodeburst; //요청부터 종료까지 걸린시간은 실행시간에 총진행시간과 도착시간 차이를 더한만큼 소요
            sum = sum + nodeburst; //총 진행시간을 총진행시간 + 실행ㅇ시간으로 업뎃
        }

        for (int i = 0; i < jobs.size(); i++) {
            if (visit[j[i].index]) continue; //이미 방문한 적이 있는 경우

            if (sum >= j[i].arrive) { //총 진행시간보다 도착시간이 작거나 같은 경우
                pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index))); //큐에 삽입
            }
        }

        if (pq.empty()) { //큐가 비어있는 경우 남아있는 디스크들 중 도착시간이 가장 작은 디스크를 큐에 삽입
            int str = -1;
            for (int i = 0; i < jobs.size(); i++) {
                if (visit[j[i].index]) continue;

                if (str == -1) { 
                    pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index)));
                    str = j[i].arrive;
                }

                else if (str == j[i].arrive) {
                    pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index)));
                    str = j[i].arrive;
                }

                else {
                    break;
                }
            }
        }
    }

    for (int i = 0; i < jobs.size(); i++) {
        answer = answer + ans[j[i].index];
    }
    return answer / jobs.size(); //소요시간 평균 리턴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<vector<int> > jobs;
    vector<int> v;
    
    v.push_back(0);
    v.push_back(3);
    jobs.push_back(v);
    v.clear();

    v.push_back(1);
    v.push_back(9);
    jobs.push_back(v);
    v.clear();

    v.push_back(2);
    v.push_back(6);
    jobs.push_back(v);
    v.clear();

    cout << solution(jobs);
    return 0;
}