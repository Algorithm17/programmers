#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool visited[10001];
vector<string> total;

void dfs(vector<vector<string>> tickets, vector<string> answer, string start,int cnt){
    // �����ϱ⿡ �� ��, ���� ���� answer�� �����Ѵ�.
    // ex) [ICE, ASE] ���� ICE�� ���� answer�� �����ϴ� ����
    answer.push_back(start);


    // ���� Ƚ���� Ƽ�� ������ Ƚ����ŭ �ݺ��Ǿ��� ��
    // �̹� ���ĺ� ������ �������� ������ ��, dfs�� �����Ͽ��⿡
    // ù ��°��, Ƽ�� ������ Ƚ����ŭ �ݺ��Ǿ��� �� ���� ��, ������.
    if(cnt == tickets.size()){
        total = answer;
        return;
    }

    for(int i=0;i<tickets.size();i++){
        if(visited[i]) continue;
        // �湮�� �迭�� ��ġ��� continue, ex) 1�� ICN, SFO 2�� ICN, ATL ~
        if(tickets[i][0] != start) continue;
        // ���� start ������ �ƴϸ� continue;
        visited[i] = true;

        // ex) [ICE, ASE] ���� �������� Ȯ���ϴ� ���� ASE�̴�.
        dfs(tickets, answer, tickets[i][1], cnt+1);

        // Ƽ�� ������ Ƚ����ŭ �ݺ��� ��, ��� ���� ����Ǿ��� ��
        // �����Ѵ�.
        if(!total.empty()) return;

        // �� �ҽ��� ���� ���� �ε����� �˻縦 ���Ʊ⿡, �湮 ���� ���� ������ �����Ѵ�.
        visited[i] = false;

    }

    // �� for�� tickets[index]�� ��� �˻��� ��, tickets[index][1] ���� ���� �� �� �ִ� ���� ���ٸ�
    // tickets[index] ��ġ �˻�� ���� �� ���̴�.
    // answer ���Ϳ��� ���ش�.
    answer.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;

    // ��������, ������ ��
    sort(tickets.begin(), tickets.end(), less<>());

    // tickets, answer, ICN, Ƚ��
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

