#include <iostream>
#include <vector>

using namespace std;

int ans = 0;
vector<int> v;

void binary(int start, int end) {
    int mid = (start + end) / 2; //start�� end�� �߾Ӱ�

    int cnt = 0; //h�� �̻� �ο�� ���� ��
    int cnt2 = 0; //h�� ���� �ο�� ���� ��

    for (int i = 0; i < v.size(); i++) {
        if (v[i] >= mid) cnt++;
    }

    cnt2 = v.size() - cnt;

    bool check = false; //H - index ���ǿ� �����ϴ��� ����

    if (cnt >= mid && cnt2 <= mid) { //������ ���
        check = true;
        if (ans < mid) ans = mid; //ans ������Ʈ
    }

    if (start == end) return; //start == end�� ��� return

    if (check) binary(mid + 1, end); //H - index ���ǿ� �����ϴ� ��� 
    else binary(start, mid); //H - index ���ǿ� �������� �ʴ� ���
}

int solution(vector<int> citations) {
    int ma = 0; //���ο���� �ִ� ã��
    for (int i = 0; i < citations.size(); i++) {
        if (ma < citations[i]) ma = citations[i];
        v.push_back(citations[i]);
    }

    binary(0, ma); //�ּڰ��� 0, �ִ��� ma�� �ΰ� �̺�Ž������

    int answer = ans; //answer ������Ʈ
    return answer;
}

int main() {
    vector<int> citations;
    citations.push_back(3);
    citations.push_back(0);
    citations.push_back(6);
    citations.push_back(1);
    citations.push_back(5);

    cout << solution(citations);
}