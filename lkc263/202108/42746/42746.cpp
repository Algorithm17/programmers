#include <string>
#include <vector>
#include <iostream>


using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    for(int i=0;i< numbers.size();i++){
        for(int j=i+1;j<numbers.size();j++){
            string s1 = to_string(numbers[i]);
            string s2 = to_string(numbers[j]);
            int loop_cnt = 0;
            if(s1.length() < s2.length()) loop_cnt = s1.length();
            else loop_cnt = s2.length();

            int k=0;
            int result_idx = 0;

            for(;k<loop_cnt;k++){
                if(s1[k] < s2[k]){
                    result_idx = i;
                    break;
                }
                else if(s2[k] < s1[k]){
                    result_idx = j;
                    break;
                }
            }

            if(k==loop_cnt){
                cout << s1 << " " <<s2 << "\n";
                if(s1 == "15" && s2 == "20"){
                    cout << s1[k-1] << " " << s2[k-1] << "\n";
                }
                string d;
                if(s1[k-1] == s2[k-1] && s1.length() < s2.length()){
                    if(s1[k-1] > s2[k]){
                        result_idx = j;
                        d = s1;
                    }
                }else{
                    if(s1[k-1] > s2[k-1]){
                        result_idx = j;
                        d = s1;
                    }
                }

                cout << d << "\n";

            }

            if(result_idx == j){
                int tmp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = tmp;
            }
        }
    }

    for(int i = numbers.size()-1; i >= 0; i--) answer += to_string(numbers[i]);

    return answer;
}

int main(){

    vector<int> vc;
    vc.push_back(0);
    vc.push_back(0);
    vc.push_back(0);

    //vc.push_back(100);
//    vc.push_back(5);
//    vc.push_back(9);
    cout << solution(vc) << "\n";


    return 0;
}
