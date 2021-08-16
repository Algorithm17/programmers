#include <iostream>
#include <vector>

using namespace std;

int parent[201]; //자신의 부모

int num;

int findParent(int a) { //자신의 부모 찾기
    if (a == parent[a]) return a;

    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) { //a와 b의 부모 연결 짓기
    int aparent = findParent(a);
    int bparent = findParent(b);

    if (aparent < bparent) {
        for (int i = 1; i <= num; i++) {
            if (parent[i] == parent[b]) parent[i] = aparent; //b의 부모와 같았던 노드들 모두 a의 부모로 업데이트
        }
        
        parent[b] = aparent;
    }
    else {
        for (int i = 1; i <= num; i++) {
            if (parent[i] == parent[a]) parent[i] = bparent; //a의 부모와 같았던 노드들 모두 b의 부모로 업데이트
        }
        parent[a] = bparent;
    }
 }

bool checkParent(int a, int b) { //부모가 같은지 체크
    if (findParent(a) == findParent(b)) return true;
    else return false;
}

int solution(int n,vector<vector<int> > computers) {
    int answer = 0;

    num = n; //컴퓨터의 대수

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) { //i와 j가 연결된 경우 같은 부모로 업데이트시켜주기!
        for (int j = 1; j <= n; j++) {
            if (computers[i - 1][j - 1] == 0) continue;

            if (i == j) continue;

            unionParent(i, j);
        }
    }

    bool check[201] = { false, }; //네트워크 개수 파악

    for (int i = 1; i <= n; i++) { //네트워크 개수 파악(부모가 몇명 존재하는지)
        if (check[parent[i]]) continue; 

        answer++;

        check[parent[i]] = true;
    }
    
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<int> > computer;

    vector<int> v;

    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    computer.push_back(v);

    v.clear();

    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    computer.push_back(v);

    v.clear();

    v.push_back(0);
    v.push_back(1);
    v.push_back(1);

    computer.push_back(v);

    cout << solution(3, computer);
    return 0;
}