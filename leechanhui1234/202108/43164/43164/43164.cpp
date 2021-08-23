#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool visit[10001]; //�湮 ����

bool check = false; //��� Ƽ���� ����ߴ��� ����

vector<string> ans; 

void backtracking(vector<vector<string> > tickets, vector<string> answer, string start, int cnt) {
    answer.push_back(start); //answer�� ����� ����

    if (cnt == tickets.size()) { //��� Ƽ�� ����� ���
        ans = answer; //ans�� answer���� ����
        check = true; //check �� true��! �� ��� ��带 �湮�ߴٰ� ǥ��
        return;
    }

    if (check) return; //��� ��带 �湮�� ���

    for (int i = 0; i < tickets.size(); i++) {
        if (visit[i]) continue; //�̹� �湮�� ������� ��� continue

        if (tickets[i][0] != start) continue; //����� ��� Ƽ�Ͽ� �����ִ� ����� ���� �ٸ� ��� continue

        visit[i] = true; //�湮�ߴٰ� ǥ��

        backtracking(tickets, answer, tickets[i][1], cnt + 1); //��Ʈ��ŷ ����

        if (check) return; //��� Ƽ���� ����� ��� return

        visit[i] = false; //�׷��� ���� ��� �湮���θ� �ٽ� false��!
    }

    answer.pop_back(); //��� ��带 �湮�� �� ���� ��� answer���� �������� ����(�� �������δ� ��� ��� �湮 �Ұ���)
    return;
}

vector<string> solution(vector<vector<string> > tickets) {
    vector<string> answer;

    vector<pair<int, int> > v;

    sort(tickets.begin(), tickets.end(), less<>()); //�������� ����

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