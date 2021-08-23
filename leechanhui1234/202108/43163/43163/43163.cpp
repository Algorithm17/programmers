#include <iostream>
#include <vector>

using namespace std;

vector<string> word; //�ܾ�
bool visit[51]; //�湮����
int answer; //�� �ܰ�� ��ȯ��ų �� �ִ��� ����

void dfs(string begin, string target, int ind, int step) {
    if (ind == -1) {
        for (int i = 0; i < word.size(); i++) {
            int len = 0; //��� �ܾ �ٸ��� ����

            for (int j = 0; j < begin.size(); j++) {
                if (begin[j] != word[i][j]) len++; 
            }

            if (len > 1) continue; //2�� �̻��� �ܾ �ٸ��� continue

            visit[i] = true; //�湮���θ� true��!
            dfs(begin, target, i, 1); //dfs����
            visit[i] = false; //�湮���θ� false��!
        }

        return;
    }

    string s = word[ind];
    bool check = true; //target�� ���� �ܾ����� üũ

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != target[i]) { 
            check = false;
            break;
        }
    }

    if (check) { //target�� ���� �ܾ��� ��� step�� answer�� ����
        if (answer == 0) answer = step;
        else {
            if (answer > step) answer = step;
        }

        return;
    }

    for (int i = 0; i < word.size(); i++) {
        if (visit[i]) continue; //�̹� �湮�� ��� continue
        int len = 0; //���� �ܾ�κ��� ���� �ܾ���� �ٸ� ���縵 ���� üũ

        for (int j = 0; j < begin.size(); j++) {
            if (s[j] != word[i][j]) len++;
        }

        if (len > 1) continue; //2�� �̻��� ���縵�� �ٸ��� continue

        visit[i] = true; //�湮
        dfs(begin, target, i, step + 1); //dfs����
        visit[i] = false; //�湮���� false��
    }
}

int solution(string begin, string target, vector<string> words) {

    for (int i = 0; i < words.size(); i++) {
        word.push_back(words[i]);
    }

    dfs(begin, target, -1, 0); //dfs����

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