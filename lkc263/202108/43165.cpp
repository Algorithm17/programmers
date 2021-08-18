#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

struct Struct{
    int cur_data;
    int cur_cnt;
};

int total;
vector<int> vc;

void bfs(vector<int> numbers, int target, int plus_minus, int cnt){
    queue<Struct> q;
    q.push({plus_minus,cnt});

    while(!q.empty()){
        Struct s = q.front();
        q.pop();


        if(s.cur_cnt==numbers.size()){
            if(s.cur_data == target){
                total += 1;
            }
            continue;
        }

        q.push({s.cur_data + numbers[s.cur_cnt], s.cur_cnt+1});
        q.push({s.cur_data - numbers[s.cur_cnt], s.cur_cnt+1});
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    bfs(numbers,target,0,0);

    answer = total;


    return answer;
}
