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

        // ��� ���� 100���� �۴ٸ� Ƚ���� 1 ������Ų��.
        if(cur_k * speeds[i] + progresses[i] < 100) cur_k += 1;

        work[i] = cur_k;
    }

    // �ʱ� ���� ���� �Ѵ�. (�ε��� 0�� °)
    int cur_data = work[0];
    int cnt = 0;
    for(int i=0;i<progresses.size();i++){
        // ���� ���� ����� �����ϰ� ���� ��, �ٸ� ����� ���´ٸ�
        if(cur_data >= work[i]){
            cnt++;
            continue;
        }
        else{
            // ���� �۾� �ð� ���� ���� ���� �۾� �ð��� �� �� ��,
            // ������Ʈ �Ѵ�.
            answer.push_back(cnt);
            cnt = 1;
            cur_data = work[i];
        }
    }

    // ������ ���� �����Ѵ�.
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
