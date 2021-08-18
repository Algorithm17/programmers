#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int in[101]; //진입차수
int out[101]; //진출차수

int solution(int n, vector<vector<int> > results) {
    int answer = 0;

    vector<int> v[101];

    for (int i = 0; i < results.size(); i++) {
        int a = results[i][0];
        int b = results[i][1];

        v[a].push_back(b); //a가 b를 꺾음
    }

    for (int i = 1; i <= n; i++) {
        queue<int> q; //i노드로부터 갈 수 있는 노드 파악

        q.push(i);

        bool visit[101] = { false, };

        int cnt = 0; //자신 포함 i노드로부터 갈 수 있는 노드들의 개수(진출차수의 개수)

        while (!q.empty()) {
            int node = q.front();

            q.pop();

            if (visit[node]) continue; //방문한 경우

            cnt++; //진출차수 개수를 증가시켜줌

            visit[node] = true;

            in[node]++; //i->node 지점으로 갈 수 있음(자신노드포함 진입차수의 개수를 증가시켜줌)

            for (int i = 0; i < v[node].size(); i++) {
                int nextnode = v[node][i]; //다음노드

                if (visit[nextnode]) continue; //다음노드가 이미 방문한 노드일 때

                q.push(nextnode); //다음 노드 삽입
            }
        }

        out[i] = cnt; //진출차수 업데이트
    }

    for (int i = 1; i <= n; i++) {
        if (in[i] + out[i] == n + 1) answer++; //진입차수 + 진출차수가 n + 1일 때 => n + 1을 한 이유는 원래 관계가 n - 1인데 계산시 자신 노드를 2번 포함했기 때문
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