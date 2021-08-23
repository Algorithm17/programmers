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

//bool visited[10000][10000];


int airplane = 1001;

int total[100][20][1001];
int main(){
    vector<vector<string>> tickets;
//    vector<pair<int,int>> vc;

    tickets.push_back({"ICN","SFO"});
    tickets.push_back({"ICN","ATL"});
    tickets.push_back({"SFO","ATL"});
    tickets.push_back({"ATL","ICN"});
    tickets.push_back({"ATL","SFO"});
//
//    solution(tickets);
//
    cout << "¹Ù²î±â Àü : " << tickets[0][1]<< "\n";
    int data = tickets[0][1][0]*100;
    data += tickets[0][1][1]*10;
    data += tickets[0][1][2];

    vector<int> total_result;
    total_result.push_back(data);
    string s[3];

    s[0] += to_string(total_result[0] / 100);
    s[1] += to_string(total_result[0] / 10 % 10);
    s[2] += to_string(total_result[0] % 100 % 10);

    int datae = 123;

    cout << "¹Ù²ï ÈÄ : " <<s << "\n";

    return 0;
}
