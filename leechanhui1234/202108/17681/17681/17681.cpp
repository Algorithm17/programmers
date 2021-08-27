#include <iostream>
#include <vector>

using namespace std;

int pow(int a, int b) {
    if (b == 0) return 1;
    else return a * pow(a, b - 1);
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    for (int i = 0; i < arr1.size(); i++) {
        int num = (arr1[i] | arr2[i]); //비트의 or연산

        string s = "";

        for (int i = 0; i < n; i++) { //num의 값을 이진수로 변환해 1이면 # 0이면 ' ' 출력
            if (pow(2, n - i - 1) <= num) {
                num -= pow(2, n - i - 1);
                s.push_back('#');
            }

            else {
                s.push_back(' ');
            }
        }
        
        answer.push_back(s);
    }
    return answer;
}

int main() {
    vector<int> arr1;
    
    arr1.push_back(9);
    arr1.push_back(20);
    arr1.push_back(28);
    arr1.push_back(18);
    arr1.push_back(11);

    vector<int> arr2;

    arr2.push_back(30);
    arr2.push_back(1);
    arr2.push_back(21);
    arr2.push_back(17);
    arr2.push_back(28);

    vector<string> v = solution(5, arr1, arr2);

    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << '\n';
    }

    return 0;
}