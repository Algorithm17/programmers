#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(string a, string b){
    return (a+b) > (b+a);
}

//     return (a+b) < (b+a); 오름 차순
//     return (a+b) > (b+a); 내림 차순




string solution(vector<int> numbers) {
    string answer = "";
    vector<string> number;

    for(int i=0;i<numbers.size();i++){
        number.push_back(to_string(numbers[i]));
    }

    sort(number.begin(),number.end(),compare);


    for(int i=0;i<numbers.size();i++){
        if(answer == "" && number[i]== "0") continue;
        answer += number[i];
    }


    if(answer == "") answer = "0";


    return answer;
}

int main(){

    vector<int> vc;
//    vc.push_back(1);
//    vc.push_back(2);
//    vc.push_back(3);
//    vc.push_back(1);
//    vc.push_back(1);
//    vc.push_back(3);


    vc.push_back(0);
    vc.push_back(0);
    vc.push_back(0);
    cout << solution(vc) << "\n";


    return 0;
}
