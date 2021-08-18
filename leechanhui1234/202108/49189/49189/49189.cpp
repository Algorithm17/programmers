#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dis[20001] = { 0, };
bool visit[20001] = { false, };

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;

    vector<int> v[20001];

    for (int i = 0; i < edge.size(); i++) {
        int a = edge[i][0];
        int b = edge[i][1];

        v[a].push_back(b);
        v[b].push_back(a);
    } //bfs�� �� �� �����ϰ� ������ �� �ֵ��� i�� ������ ������ vector�� �㵵�� ��ȯ

    queue<pair<int, int> > q; //node, distance

    q.push({ 1, 0 });

    int ma = 0; //���� �� ����� �Ÿ�

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;

        q.pop();

        if (visit[node]) continue; //�湮�� ����� ���

        if (ma < distance) ma = distance; //ma������ �Ÿ��� ū ��� �� �Ÿ������� ��ȯ

        visit[node] = true;

        dis[node] = distance; //node�� �Ÿ��� distance�� �Ÿ������� ������Ʈ

        for (int i = 0; i < v[node].size(); i++) {
            int nextnode = v[node][i]; //���� ���
            int nextdis = distance + 1; //���� ������ �Ÿ���

            if (visit[nextnode]) continue; //������带 �̹� �湮�� ��� continue

            q.push({ nextnode, nextdis }); //ť�� ���� ���� �� �Ÿ����� ����
        }
    }

    for (int i = 1; i <= n; i++) { //�ִ񰪰� dis�迭���� ������ ��� answer�� ����������
        if (ma == dis[i]) answer++;
    }

    return answer; //answer�� ���
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int> > edge;

    vector<int> v;

    v.push_back(3);
    v.push_back(6);

    edge.push_back(v);

    v.clear();

    v.push_back(4);
    v.push_back(3);

    edge.push_back(v);

    v.clear();

    v.push_back(3);
    v.push_back(2);

    edge.push_back(v);

    v.clear();

    v.push_back(1);
    v.push_back(3);

    edge.push_back(v);

    v.clear();

    v.push_back(1);
    v.push_back(2);

    edge.push_back(v);

    v.clear();

    v.push_back(2);
    v.push_back(4);

    edge.push_back(v);

    v.clear();

    v.push_back(5);
    v.push_back(2);

    edge.push_back(v);

    v.clear();

    cout << solution(6, edge);
    return 0;
}