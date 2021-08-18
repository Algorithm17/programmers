#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // yellow ���� �簢�� : a, b (����, ����)
    // brown+yellow ū �簢�� : (a + 2) x (b + 2) : (����, ����)

    int a, b;
    int big_square_extent = brown + yellow;

    // a x b + 2(a + b) + 4 = ū �簢��
    // a x b == yellow
    // 24 + 2(a + b) + 4 = 48
    // a + b = 10   ���� �簢���� ���� + ����

    int cal_value = (big_square_extent - 4 - yellow)/2;
    // cal_value == ���� �簢���� ���� + ����

    // 3 : 1 + �� ����(2)
    for(int col = 1; col < cal_value;col++){
        for(int row = 1; row <= col; row++){
            if(col+row==cal_value && col*row == yellow){
                int width, length;
                if(col < row){
                    width = row;
                    length = col;
                }else{
                    width = col;
                    length = row;
                }
                answer.push_back(width+2);
                answer.push_back(length+2);
                break;
            }
        }
    }




    return answer;
}
