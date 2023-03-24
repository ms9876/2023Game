#include <iostream>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

int main()
{
    //목표 빙고수 정하기
    int target;
    cout << "목표 빙고 수를 입력하세요 : ";
    cin >> target;

    //숫자 1~25까지 넣기
    int num[25] = {};
    for (int i = 0; i < 25; i++) {
        num[i] = i + 1;
    }

    //섞기
    srand((unsigned int)time(NULL));
    int temp, idx1, idx2;
    for (int i = 0; i < 100; i++) {
        idx1 = rand() % 25;
        idx2 = rand() % 25;
        temp = num[idx1];
        num[idx1] = num[idx2];
        num[idx2] = temp;
    }

    //빙고
    while (true)
    {
        system("cls");

        //빙고 표 출력
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (num[(i * 5) + j] == -1) cout << "*\t";
                else cout << num[(i * 5) + j] << "\t";
            }
            cout << "\n";
        }

        //숫자 체크
        int input;
        cout << "숫자를 입력하세요! (종료 : 0) : ";
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

        //빙고 체크
        int bingo = 0;
        for (int i = 0; i < 5; i++) {
            int h_star = 0, v_star = 0;
            for (int j = 0; j < 5; j++) {
                //가로
                if (num[(i * 5) + j] == -1)
                    h_star++;
                //세로
                if (num[(j * 5) + i] == -1)
                    v_star++;
            }
            if (h_star == 5) bingo++;
            if (v_star == 5) bingo++;
        }
        //대각선
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
            cout << "************** 빙고 완성 **************" << endl;
            system("pause");
            exit(0);
        }
        cout << endl << "bingo line : " << bingo << endl;
    }
}