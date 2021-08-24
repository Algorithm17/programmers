#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10001]; //방문 여부

bool check = false; //모든 티켓을 사용했는지 여부

vector<string> ans;

void backtracking(vector<vector<string> > tickets, vector<string> answer, string start, int cnt) {
    answer.push_back(start); //answer에 출발지 삽입

    if (cnt == tickets.size()) { //모든 티켓 사용한 경우
        ans = answer; //ans에 answer벡터 삽입
        check = true; //check 를 true로! 즉 모든 노드를 방문했다고 표시

        cout << "사이즈 만큼 입력 완료 되었을 때 "<< "\n";

        for(int i=0;i<answer.size();i++){
            cout << answer[i] << " ";
        }
        cout << "\n";
        return;
    }

    if (check) return; //모든 노드를 방문한 경우

    for (int i = 0; i < tickets.size(); i++) {
        if (visit[i]) continue; //이미 방문한 출발지인 경우 continue

        if (tickets[i][0] != start) continue; //출발지 명과 티켓에 나와있는 출발지 명이 다른 경우 continue

        visit[i] = true; //방문했다고 표시
        cout << tickets[i][0] << " " << tickets[i][1] << " 횟수 : " << cnt + 1 <<"\n";
        backtracking(tickets, answer, tickets[i][1], cnt + 1); //백트래킹 수행

        if (check) return; //모든 티켓을 사용한 경우 return

        visit[i] = false; //그렇지 않은 경우 방문여부를 다시 false로!
    }

    answer.pop_back(); //모든 노드를 방문할 수 없는 경우 answer에서 여행지를 꺼냄(이 여행지로는 모든 노드 방문 불가능)
    return;
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer;

    vector<pair<int, int> > v;

    sort(tickets.begin(), tickets.end(), less<>()); //오름차순 정렬

    for(int i=0;i<tickets.size();i++){
        for(int j=0;j<2;j++){
            cout << tickets[i][j]  << " ";
        }
        cout << "\n";
    }
    backtracking(tickets, answer, "ICN", 0);

    answer = ans;
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

