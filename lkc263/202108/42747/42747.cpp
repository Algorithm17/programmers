#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end());

    for(int i=0;i<citations.size();i++){
        int h = citations[i];
        // h 번 이상 인용된 눈문
        int cnt = 0 ;
        bool check = false;
        for(int j=0;j<citations.size();j++){
            if(h <= citations[i]) cnt++;
        }

        // 나머지 논문이 h번 이하 인용되었다면
        int quoted = citations.size() - cnt;


        // h번 이상 인용된 논문
        int cnt2 = 0;
        for(int k=0;k<i;k++){ // 나머지
            if(h>=citations[k]) cnt2++;
        }


        if(cnt >= h && cnt2 <= h){
            answer = h;
        }

        if(cnt < h || cnt2 > h){
            break;
        }

    }

    return answer;
}

int main(){
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << solution(citations) << "\n";

    return 0;
}
