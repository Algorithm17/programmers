#include <iostream>
#include <vector>

using namespace std;

vector<string> word; //단어
bool visit[51]; //방문여부
int answer; //몇 단계로 변환시킬 수 있는지 여부

void dfs(string begin, string target, int ind, int step) {
    if (ind == -1) {
        for (int i = 0; i < word.size(); i++) {
            int len = 0; //몇개의 단어가 다른지 여부

            for (int j = 0; j < begin.size(); j++) {
                if (begin[j] != word[i][j]) len++; 
            }

            if (len > 1) continue; //2개 이상의 단어가 다르면 continue

            visit[i] = true; //방문여부를 true로!
            dfs(begin, target, i, 1); //dfs수행
            visit[i] = false; //방문여부를 false로!
        }

        return;
    }

    string s = word[ind];
    bool check = true; //target과 같은 단어인지 체크

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != target[i]) { 
            check = false;
            break;
        }
    }

    if (check) { //target과 같은 단어인 경우 step을 answer에 저장
        if (answer == 0) answer = step;
        else {
            if (answer > step) answer = step;
        }

        return;
    }

    for (int i = 0; i < word.size(); i++) {
        if (visit[i]) continue; //이미 방문한 경우 continue
        int len = 0; //현재 단어로부터 다음 단어까지 다른 스펠링 개수 체크

        for (int j = 0; j < begin.size(); j++) {
            if (s[j] != word[i][j]) len++;
        }

        if (len > 1) continue; //2개 이상의 스펠링이 다르면 continue

        visit[i] = true; //방문
        dfs(begin, target, i, step + 1); //dfs수행
        visit[i] = false; //방문여부 false로
    }
}

int solution(string begin, string target, vector<string> words) {

    for (int i = 0; i < words.size(); i++) {
        word.push_back(words[i]);
    }

    dfs(begin, target, -1, 0); //dfs수행

    return answer;
}

int main() {
    vector<string> words;

    words.push_back("hot");
    words.push_back("dot");
    words.push_back("dog");
    words.push_back("lot");
    words.push_back("log");

    cout << solution("hit", "cog", words);
}