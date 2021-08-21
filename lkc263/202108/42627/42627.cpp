#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct cmp{

    bool operator()(vector<int> a, vector<int> b){
        return a.at(1) > b.at(1);
    }
};

int solution(vector<vector<int>> jobs) {
    // jobs : ��⿭
    int answer=0;
    int j=0;
    int time = 0;
    sort(jobs.begin(),jobs.end());
    priority_queue<vector<int>,vector<vector<int>>,cmp> pq;

    while(!pq.empty() || j<jobs.size()){
        // ��⿭���� �ִµ�, ���� �ð����� �۰ų� ������
        // ���� j ��°�� jobs�� ũ�� ���� �۴ٸ�
        if(j < jobs.size() && jobs[j][0] <= time ){
            // j�� jobs.size�� ���� �ʴ´ٸ�
            pq.push(jobs[j++]);
            continue;
        }

        if(!pq.empty()){
            time += pq.top()[1];
            // pq.top()[1] : ���� �ð�
            answer += time - pq.top()[0];
            // �� �ð� - i ��° ���� �ð� (pq.top()[0])

            pq.pop();
        }
        else{
            // ť�� ���̻� �����Ͱ� ���� ��, ���� �� ��� ���� ���� ������ �̵��Ѵ�.
            time = jobs[j][0];
        }
    }

    return answer/jobs.size();

}
