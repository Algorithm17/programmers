#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int work[101] = { 0, }; //배포가 몇 일 뒤 이루어지는지 여부

    for (int i = 0; i < progresses.size(); i++) { //배포일 계산
        work[i] = (100 - progresses[i]) / speeds[i];

        if ((100 - progresses[i]) % speeds[i] != 0) work[i] += 1;
    }

    int ans = 0; //몇개의 기능이 배포되는지 여부
    int ma = -1; //최댓값

    for (int i = 0; i < progresses.size(); i++) {
        if (i == 0) { //i == 0인 경우 자기자신의 기능은 먼저 배포되고 시작
            ans++;
            ma = work[i];
            continue;
        }

        if (ma >= work[i]) { //최댓값보다 배포일이 적은경우 기능들 같이 배포 가능
            ans++;
            continue;
        }

        else { //그렇지 않은 경우 기능들 앞에것과 같이 배포 불가
            answer.push_back(ans);
            ans = 1;
            ma = work[i];
            continue;
        }
    }

    answer.push_back(ans);
    return answer;
}

int main() {
    vector<int> progresses;
    vector<int> speeds;

    progresses.push_back(95);
    progresses.push_back(90);
    progresses.push_back(99);
    progresses.push_back(99);
    progresses.push_back(80);
    progresses.push_back(99);

    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);
    speeds.push_back(1);

    vector<int> v = solution(progresses, speeds);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << ' ';
    }
}