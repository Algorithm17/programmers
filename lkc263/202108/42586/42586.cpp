#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int work[101] = {0,};

    for(int i=0;i<progresses.size();i++){
        // progress[idx] + (speeds * k) == 100 (%)
        int cur_k = (100 - progresses[i])/speeds[i];

        // 결과 값이 100보다 작다면 횟수를 1 증가시킨다.
        if(cur_k * speeds[i] + progresses[i] < 100) cur_k += 1;

        work[i] = cur_k;
    }

    // 초기 값을 삽입 한다. (인덱스 0번 째)
    int cur_data = work[0];
    int cnt = 0;
    for(int i=0;i<progresses.size();i++){
        // 먼저 들어온 기능이 배포하고 있을 때, 다른 기능이 들어온다면
        if(cur_data >= work[i]){
            cnt++;
            continue;
        }
        else{
            // 현재 작업 시간 보다 새로 들어온 작업 시간이 더 길 때,
            // 업데이트 한다.
            answer.push_back(cnt);
            cnt = 1;
            cur_data = work[i];
        }
    }

    // 마지막 값을 삽입한다.
    answer.push_back(cnt);


    return answer;
}


int main(){
    vector<int> progresses, speeds;
    vector<int> result;
//    progresses.push_back(93);
//    progresses.push_back(30);
//    progresses.push_back(55);
//
//    speeds.push_back(1);
//    speeds.push_back(30);
//    speeds.push_back(5);


//    progresses.push_back(95);
//    progresses.push_back(90);
//    progresses.push_back(99);
//    progresses.push_back(99);
//    progresses.push_back(80);
//    progresses.push_back(99);
//
//    speeds.push_back(1);
//    speeds.push_back(1);
//    speeds.push_back(1);
//    speeds.push_back(1);
//    speeds.push_back(1);
//    speeds.push_back(1);

    result = solution(progresses,speeds);

    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }

    cout << "\n";

    return 0;
}
