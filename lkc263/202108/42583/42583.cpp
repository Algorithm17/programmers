#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int cur_weight = 0;  // ���� ���ο� �ö� �ִ� �� ����
    // ���ο� �ö� �ִ� ��, ������ ���� �Ÿ�
    queue<vector<int>> q_cnt, bridgeOn;

    while(true){
        int size = bridgeOn.size();

        for(int i=0;i<size;i++){
        }

        if(truck_weights.size() > 0 && cur_weight + truck_weights.at(0))
    }

    return answer;
}

int main(){


    vector<int> vc;

    vc.push_back(10);

    cout << solution(100, 100, vc) << "\n";



    return 0;
}
