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
    } //bfs를 좀 더 수월하게 수행할 수 있도록 i와 인접한 노드들을 vector에 담도록 변환

    queue<pair<int, int> > q; //node, distance

    q.push({ 1, 0 });

    int ma = 0; //가장 먼 노드의 거리

    while (!q.empty()) {
        int node = q.front().first;
        int distance = q.front().second;

        q.pop();

        if (visit[node]) continue; //방문한 노드인 경우

        if (ma < distance) ma = distance; //ma값보다 거리가 큰 경우 그 거리값으로 변환

        visit[node] = true;

        dis[node] = distance; //node의 거리를 distance의 거리값으로 업데이트

        for (int i = 0; i < v[node].size(); i++) {
            int nextnode = v[node][i]; //다음 노드
            int nextdis = distance + 1; //다음 노드까지 거리값

            if (visit[nextnode]) continue; //다음노드를 이미 방문한 경우 continue

            q.push({ nextnode, nextdis }); //큐에 다음 노드와 그 거리값을 삽입
        }
    }

    for (int i = 1; i <= n; i++) { //최댓값과 dis배열값이 동일한 경우 answer값 증가시켜줌
        if (ma == dis[i]) answer++;
    }

    return answer; //answer값 출력
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