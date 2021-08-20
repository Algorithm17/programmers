#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Disk {
    int arrive; //�����ð�
    int burst; //����ð�
    int index; //�ڽ��� ���� �ε���
};

Disk j[501];

bool visit[501]; //�湮�ߴ��� ����

int ans[501]; //�۾� ��û���κ��� ������� �ɸ� �ð�

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
        if (str == j[i].arrive) { //��ũ�� �� �����ð��� ���� ���� ���
            pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index)));
        }
    }

    int sum = 0; //�� ����ð�

    while (!pq.empty()) {
        int nodeburst = -pq.top().first;
        int nodearrive = -pq.top().second.first;
        int nodeindex = -pq.top().second.second;

        pq.pop();

        if (visit[nodeindex]) continue; //��� �ε����� �湮�� ���� �ִ��� ����

        visit[nodeindex] = true; 

        if (sum <= nodearrive) { //�� ����ð��� �����ð����� �۰ų� ���� ���
            ans[nodeindex] = nodeburst; //��û���� ������� �ɸ� �ð��� ����ð���ŭ�� �ҿ�
            sum = nodearrive + nodeburst; //�� ����ð��� �����ð� + ����ð����� ����
        }

        else { //�� ����ð��� �����ð����� ū ���
            ans[nodeindex] = sum - nodearrive + nodeburst; //��û���� ������� �ɸ��ð��� ����ð��� ������ð��� �����ð� ���̸� ���Ѹ�ŭ �ҿ�
            sum = sum + nodeburst; //�� ����ð��� ������ð� + ���ष�ð����� ����
        }

        for (int i = 0; i < jobs.size(); i++) {
            if (visit[j[i].index]) continue; //�̹� �湮�� ���� �ִ� ���

            if (sum >= j[i].arrive) { //�� ����ð����� �����ð��� �۰ų� ���� ���
                pq.push(make_pair(-j[i].burst, make_pair(-j[i].arrive, -j[i].index))); //ť�� ����
            }
        }

        if (pq.empty()) { //ť�� ����ִ� ��� �����ִ� ��ũ�� �� �����ð��� ���� ���� ��ũ�� ť�� ����
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
    return answer / jobs.size(); //�ҿ�ð� ��� ����
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