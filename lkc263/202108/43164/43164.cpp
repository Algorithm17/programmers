#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Struct{
    int cur_index;
    int cnt;
};

// 제일 큰 수 ZZZ : 9990
bool visited[9999][9999];

vector<int> bfs(vector<vector<int>> vc, int idx){
    queue<Struct> q; // 인덱스, 횟수

    vector<int> total_result;
    vector<int> cur_result;
    for(int i=0;i<vc.size();i++){
        total_result.push_back(0);
    }
    q.push({idx,0});
    // 첫 번째 데이터 삽입
    cur_result.push_back(vc[idx][0]);

    while(!q.empty()){
        Struct s = q.front();
        q.pop();


        if(s.cnt == vc.size()+1){
            int i=0;
            for(;i<vc.size()+1;i++){
                if(total_result[i] < cur_result[i]) break;

            }
            if(i!=vc.size()+1) total_result = cur_result;
        }

        if(visited[vc[s.cur_index][0]][vc[s.cur_index][1]]) continue;
        visited[vc[s.cur_index][0]][vc[s.cur_index][1]] = true;

        // push 되는 데이터 넣는다.
        cur_result.push_back(vc[s.cur_index][0]);


        for(int i=0;i<vc.size();i++){

            // 1 3
            // 3 2
            int first_data = vc[i][0];
            int second_data = vc[i][1];   // 다음 데이터

            if(visited[first_data][second_data]) continue;

            for(int j=0;j<vc.size();j++){
                if(i==j) continue;
                if(visited[vc[j][0]][vc[j][1]]) continue;
                if(vc[i][1] == vc[j][0]) q.push({j,s.cnt+1});
            }
        }
    }

    return total_result;

}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<vector<int>> tickets_to_int;
    int icn_data = 'I'*100 + 'C'*10 +'N';


    vector<int> total_result;

    // string -> int 형으로 변경
    for(int i=0;i<tickets.size();i++){
        // 나중 결과 값을 찾기 위해 사용한다.
        total_result.push_back(0);
        vector<int> vc;
        for(int j=0;j<2;j++){
            int str_to_int = 0;
            str_to_int += tickets[i][j][0] * 100;
            str_to_int += tickets[i][j][1] * 10;
            str_to_int += tickets[i][j][2];
            vc.push_back(str_to_int);
        }
        tickets_to_int.push_back({vc[0],vc[1]});
    }


    for(int i=1;i<tickets_to_int.size();i++){
        if(tickets_to_int[i][0] == icn_data){
            int cur_index = i;
            vector<int> vc;
            vc = bfs(tickets_to_int,i);

            int i=0;
            for(;i<vc.size()+1;i++){
                if(total_result[i] < vc[i]) break;

            }
            if(i!=vc.size()+1) total_result = vc;
        }
    }

    for(int i=0;i<vc.size()+1;i++){
        string s;

        s += to_string(total_result[0] / 100);
        s += to_string(total_result[0] / 10 % 10);
        s += to_string(total_result[0] % 100 % 10);;

        answer.push_back(s);
    }




    return answer;
}


int airplane = 1001;

int total[100][20][1001];
int main(){
    vector<vector<string>> tickets;

    tickets.push_back({"ICN","SFO"});
    tickets.push_back({"ICN","ATL"});
    tickets.push_back({"SFO","ATL"});
    tickets.push_back({"ATL","ICN"});
    tickets.push_back({"ATL","SFO"});


    solution(tickets);


    return 0;
}
