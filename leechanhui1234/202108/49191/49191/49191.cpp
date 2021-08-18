#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int in[101]; //��������
int out[101]; //��������

int solution(int n, vector<vector<int> > results) {
    int answer = 0;

    vector<int> v[101];

    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0];
        int b = results[i][1];

        v[a].push_back(b); //a�� b�� ����
    }

    for (int i = 1; i <= n; i++) {
        queue<int> q; //i���κ��� �� �� �ִ� ��� �ľ�

        q.push(i);

        bool visit[101] = { false, };

        int cnt = 0; //�ڽ� ���� i���κ��� �� �� �ִ� ������ ����(���������� ����)

        while (!q.empty()) {
            int node = q.front();

            q.pop();

            if (visit[node]) continue; //�湮�� ���

            cnt++; //�������� ������ ����������

            visit[node] = true;

            in[node]++; //i->node �������� �� �� ����(�ڽų������ ���������� ������ ����������)

            for (int i = 0; i < v[node].size(); i++) {
                int nextnode = v[node][i]; //�������

                if (visit[nextnode]) continue; //������尡 �̹� �湮�� ����� ��

                q.push(nextnode); //���� ��� ����
            }
        }

        out[i] = cnt; //�������� ������Ʈ
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] + out[i] == n + 1) answer++; //�������� + ���������� n + 1�� �� => n + 1�� �� ������ ���� ���谡 n - 1�ε� ���� �ڽ� ��带 2�� �����߱� ����
    }
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int> > results;

    vector<int> v;

    v.push_back(4);
    v.push_back(3);

    results.push_back(v);

    v.clear();

    v.push_back(4);
    v.push_back(2);

    results.push_back(v);

    v.clear();

    v.push_back(3);
    v.push_back(2);

    results.push_back(v);

    v.clear();

    v.push_back(1);
    v.push_back(2);

    results.push_back(v);

    v.clear();

    v.push_back(2);
    v.push_back(5);

    results.push_back(v);

    v.clear();

    cout << solution(4, results);
    return 0;
}