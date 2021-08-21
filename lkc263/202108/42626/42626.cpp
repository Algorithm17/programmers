#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;



int solution(vector<int> scoville, int K) {
    int answer = 0;

    priority_queue<int,vector<int>> pq;

    for(int i=0;i<scoville.size();i++){
        pq.push(-scoville[i]);
    }
    bool check = false;
    while(!pq.empty()){
        int data = -pq.top();
        pq.pop();

        if(data == K){
            check = true;
            break;
        }

        if(pq.empty()) break;  // 비어 있다면 나가기

        answer++;


        int next_node = -pq.top();
        pq.pop();
        pq.push(-(data+next_node*2));
    }


    if(check==false) answer = -1;

    return answer;
}

int main(){
    vector<int> vc;
    vc.push_back(1);
    vc.push_back(2);
    vc.push_back(3);
    vc.push_back(9);
    vc.push_back(10);
    vc.push_back(12);

    solution(vc,7);
    return 0;
}
