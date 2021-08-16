#include <iostream>
#include <vector>

using namespace std;

int parent[201]; //�ڽ��� �θ�

int num;

int findParent(int a) { //�ڽ��� �θ� ã��
    if (a == parent[a]) return a;

    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b) { //a�� b�� �θ� ���� ����
    int aparent = findParent(a);
    int bparent = findParent(b);

    if (aparent < bparent) {
        for (int i = 1; i <= num; i++) {
            if (parent[i] == parent[b]) parent[i] = aparent; //b�� �θ�� ���Ҵ� ���� ��� a�� �θ�� ������Ʈ
        }
        
        parent[b] = aparent;
    }
    else {
        for (int i = 1; i <= num; i++) {
            if (parent[i] == parent[a]) parent[i] = bparent; //a�� �θ�� ���Ҵ� ���� ��� b�� �θ�� ������Ʈ
        }
        parent[a] = bparent;
    }
 }

bool checkParent(int a, int b) { //�θ� ������ üũ
    if (findParent(a) == findParent(b)) return true;
    else return false;
}

int solution(int n,vector<vector<int> > computers) {
    int answer = 0;

    num = n; //��ǻ���� ���

    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= n; i++) { //i�� j�� ����� ��� ���� �θ�� ������Ʈ�����ֱ�!
        for (int j = 1; j <= n; j++) {
            if (computers[i - 1][j - 1] == 0) continue;

            if (i == j) continue;

            unionParent(i, j);
        }
    }

    bool check[201] = { false, }; //��Ʈ��ũ ���� �ľ�

    for (int i = 1; i <= n; i++) { //��Ʈ��ũ ���� �ľ�(�θ� ��� �����ϴ���)
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