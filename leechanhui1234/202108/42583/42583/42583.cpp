#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {

    int answer = 0;

    int time = 0;

    queue<int> cross; // 건너는 트럭 
    queue<int> t; // 다리에서 머무르는 시간 
    queue<int> daegi; //대기하는 트럭
    queue<int> complete; //완료 트럭

    for (int i = 0; i < truck_weights.size(); i++) { //대기트럭에 트럭들 삽입
        daegi.push(truck_weights[i]);
    }

    int sum = 0; //트럭 무게의 총 합

    for (time = 1; ; time++) {

        int tim;

        if (!t.empty()) { //다리에서 머무르는 시간 큐가 비지 않았을 경우
            tim = t.front(); //시간 확인
        }

        if (tim == bridge_length) { //다리 길이와 머무르는 시간이 동일한 경우
            t.pop(); //t를 queue에서 빼냄

            int truck = cross.front(); //다리 건너는 트럭 빼냄

            cross.pop();

            sum -= truck; // 총 트럭 무게에서 다리 건너는 트럭 무게 뺌

            complete.push(truck); //트럭을 완료 트럭에 삽입
        }

        if (!t.empty()) { //t가 비지 않았을 경우

            for (int i = 0; i < t.size(); i++) { //하나하나 시간들을 1추가시킴
                int ti = t.front();

                t.pop();

                t.push(ti + 1);

            }

        }

        if (daegi.empty() && cross.empty()) break; //대기하는 트럭도, 건너는 트럭도 없을 시 break

        int truck = -1;

        if (!daegi.empty()) { //대기하는 트럭이 비지 않았을 경우
            truck = daegi.front(); //대기 큐에서 트럭 하나를 꺼냄
        }

        if (sum + truck <= weight && truck != -1) { //대기 트럭이 존재하고 다리가 트럭 무게를 견딜 수 있을 때
            daegi.pop(); //대기 큐에서 완전 꺼냄
            cross.push(truck); //다리 건너는 큐에 트럭을 옮김
            t.push(1); //그 시간을 1로 정함
            sum += truck; //다리 위에 있는 트럭의 합에 그 트럭을 더함
        }
    }

    answer = time; //시간을 answer변수에 업데이트
    return answer;
}

int main() {
    vector<int> truck_weights;
    truck_weights.push_back(7);
    truck_weights.push_back(4);
    truck_weights.push_back(5);
    truck_weights.push_back(6);
    cout << solution(2, 10, truck_weights);
}