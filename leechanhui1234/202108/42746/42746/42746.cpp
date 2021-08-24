#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string s1, string s2) { //두 문자열을 붙이면서 비교
    return (s1 + s2) > (s2 + s1);
}

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> number;

    for (int i = 0; i < numbers.size(); i++) { //정수를 문자열로 변환
        number.push_back(to_string(numbers[i])); 
    }

    sort(number.begin(), number.end(), compare); //정렬

    for (int i = 0; i < number.size(); i++) {
        if (answer == "" && number[i] == "0") continue; //0인 경우 continue
        answer = answer + number[i];
    }

    if (answer.size() == 0) answer = "0"; //아예 빈 문자열인 경우 0을 추가시켜줌
    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> numbers;

    numbers.push_back(3);
    numbers.push_back(30);
    numbers.push_back(34);
    numbers.push_back(5);
    numbers.push_back(9);

    cout << solution(numbers);
    return 0;
}