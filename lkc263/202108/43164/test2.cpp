#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vc;

    vc.push_back(4);
    vc.push_back(3);
    vc.push_back(2);
    vc.push_back(5);
    vc.push_back(1);


    sort(vc.begin(),vc.end());

    cout << "1���� ���� Ȯ��" << "\n";
    for(int i=0;i<5;i++){
        cout << vc[i]  << " ";
    }



    cout << "\n\n";
    cout << "2���� ���� Ȯ��" << "\n";

    vector<vector<int>> vc2;

    int data = 3;
    for(int i=0;i<5;i++){
        vector<int> vc_data;
        for(int j=0;j<2;j++){
            vc_data.push_back(data-i+j);
        }
        vc2.push_back(vc_data);

        if(i == 4) data = 6;
    }


    sort(vc2.begin(),vc2.end());



    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            cout << vc2[i][j] << " ";
        }
        cout <<"\n";
    }


    cout << "\n";
    cout << "2���� ���� ���� ���� Ȯ��" << "\n";

    // sort(����.begin(),����.end(),greater<�ڷ���>());    => ���� ����
    sort(vc2.begin(),vc2.end(),greater<vector<int>>());



    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            cout << vc2[i][j] << " ";
        }
        cout <<"\n";
    }



    cout << "\n";
    cout << "2���� ���� ���� ���� Ȯ��" << "\n";

    // sort(����.begin(),����.end(),less<�ڷ���>());    => ���� ����
    sort(vc2.begin(),vc2.end(),less<vector<int>>());



    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            cout << vc2[i][j] << " ";
        }
        cout <<"\n";
    }



    return 0;
}
