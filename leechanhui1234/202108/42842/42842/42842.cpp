#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= 2000000; i++) {
        int b = i;
        int a = (brown - 4) / 2 - b; //방정식을 b식으로 저장

        if (a * b == yellow) {
            int ma = max(a + 2, b + 2); //가로길이
            int mi = min(a + 2, b + 2); //세로길이

            answer.push_back(ma);
            answer.push_back(mi);

            break;
        }
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector <int> v;

    v = solution(10, 2);

    cout << v[0] << ' ' << v[1];
    return 0;
}