#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    //��ǥ ����� ���ϱ�
    int target;
    cout << "��ǥ ���� ���� �Է��ϼ��� : ";
    cin >> target;

    //���� 1~25���� �ֱ�
    int num[25] = {};
    for (int i = 0; i < 25; i++) {
        num[i] = i + 1;
    }

    //����
    srand((unsigned int)time(NULL));
    int temp, idx1, idx2;
    for (int i = 0; i < 100; i++) {
        idx1 = rand() % 25;
        idx2 = rand() % 25;
        temp = num[idx1];
        num[idx1] = num[idx2];
        num[idx2] = temp;
    }

    //����
    while (true)
    {
        system("cls");

        //���� ǥ ���
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (num[(i * 5) + j] == -1) cout << "*\t";
                else cout << num[(i * 5) + j] << "\t";
            }
            cout << "\n";
        }

        //���� üũ
        int input;
        cout << "���ڸ� �Է��ϼ���! (���� : 0) : ";
        cin >> input;
        if (input == 0) {
            exit(0);
        }
        for (int i = 0; i < 25; i++) {
            if (num[i] == input) {
                num[i] = -1;
                break;
            }
        }

        //���� üũ
        int bingo = 0;
        for (int i = 0; i < 5; i++) {
            int h_star = 0, v_star = 0;
            for (int j = 0; j < 5; j++) {
                //����
                if (num[(i * 5) + j] == -1)
                    h_star++;
                //����
                if (num[(j * 5) + i] == -1)
                    v_star++;
            }
            if (h_star == 5) bingo++;
            if (v_star == 5) bingo++;
        }
        //�밢��
        int d_star = 0;
        for (int i = 0; i < 5; i += 6) {
            if (num[i] == -1) {
                d_star++;
            }
        }
        if (d_star == 5) bingo++;
        d_star = 0;
        for (int i = 0; i < 5; i += 4) {
            if (num[i] == -1) {
                d_star++;
            }
        }
        if (d_star == 5) bingo++;

        if (bingo == target) {
            cout << "************** ���� �ϼ� **************" << endl;
            system("pause");
            exit(0);
        }
        cout << endl << "bingo line : " << bingo << endl;
    }
}