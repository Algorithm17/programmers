#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[10001];
vector<string> total;

void dfs(vector<vector<string>> tickets, vector<string> answer, string start,int cnt){
    // 시작하기에 앞 서, 시작 값을 answer에 삽입한다.
    // ex) [ICE, ASE] 면은 ICE를 먼저 answer에 삽입하는 형태
    answer.push_back(start);


    // 현재 횟수가 티켓 사이즈 횟수만큼 반복되었을 때
    // 이미 알파벳 순으로 오름차순 정렬한 후, dfs를 실행하였기에
    // 첫 번째로, 티켓 사이즈 횟수만큼 반복되었을 때 대입 후, 나간다.
    if(cnt == tickets.size()){
        total = answer;
        return;
    }

    for(int i=0;i<tickets.size();i++){
        if(visited[i]) continue;
        // 방문한 배열의 위치라면 continue, ex) 1번 ICN, SFO 2번 ICN, ATL ~
        if(tickets[i][0] != start) continue;
        // 현재 start 공항이 아니면 continue;
        visited[i] = true;

        // ex) [ICE, ASE] 면은 다음으로 확인하는 것은 ASE이다.
        dfs(tickets, answer, tickets[i][1], cnt+1);

        // 티켓 사이즈 횟수만큼 반복된 후, 결과 값이 저장되었을 때
        // 종료한다.
        if(!total.empty()) return;

        // 위 소스를 통해 현재 인덱스는 검사를 맞쳤기에, 방문 하지 않은 곳으로 변경한다.
        visited[i] = false;

    }

    // 위 for문 tickets[index]를 모두 검사한 후, tickets[index][1] 다음 차례 될 수 있는 것이 없다면
    // tickets[index] 위치 검사는 끝이 난 것이다.
    // answer 벡터에서 빼준다.
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    // 오름차순, 정렬한 후
    sort(tickets.begin(), tickets.end(), less<>());

    // tickets, answer, ICN, 횟수
    dfs(tickets, answer,"ICN",0);

    answer = total;

    return answer;
}

int main() {
    vector<vector<string> > tickets;

    vector<string> v;

    v.push_back("ICN");
    v.push_back("SFO");

    tickets.push_back(v);

    v.clear();

    v.push_back("ICN");
    v.push_back("ATL");

    tickets.push_back(v);

    v.clear();

    v.push_back("SFO");
    v.push_back("ATL");

    tickets.push_back(v);

    v.clear();

    v.push_back("ATL");
    v.push_back("ICN");

    tickets.push_back(v);

    v.clear();

    v.push_back("ATL");
    v.push_back("SFO");

    tickets.push_back(v);

    v.clear();

    vector<string> s = solution(tickets);

    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << ' ';
    }
}

