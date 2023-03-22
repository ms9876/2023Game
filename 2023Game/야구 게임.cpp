#include <iostream>
using  namespace std;
// shuffle 알고리즘 

int iStrike = 0;
int iBall = 0;
int iGameCount = 1;
int iInputNum[3];
int iNumder[9] = {};

void Player1() {
	iStrike = 0;
	iBall = 0;
	cout << iGameCount << "회" << endl;
	cout << "Player1 차례! 1 ~ 9 사이의 숫자 중 숫자 3개를 입력하세요 (0 : 종료) : ";
	cin >> iInputNum[0] >> iInputNum[1] >> iInputNum[2];
	//종료 조건
	if (iInputNum[0] == 0 || iInputNum[1] == 0 || iInputNum[2] == 0)
		return;
	else if (iInputNum[0] < 0 || iInputNum[0] > 9
		|| iInputNum[1] < 0 || iInputNum[1] > 9
		|| iInputNum[2] < 0 || iInputNum[2] > 9) {
		cout << "잘못된 숫자를 입력했습니다." << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (iNumder[i] == iInputNum[i]) {
				if (i == j) {
					iStrike++;
				}
				else {
					iBall++;
				}
			}
		}
	}
	iGameCount++;
	if (iStrike == 3) {
		cout << "Player1 정답!";
		return;
	}
	else {
		cout << iStrike << "Skrike" << " " << iBall << "Ball" << endl;
	}
}

void Player2() {
	iStrike = 0;
	iBall = 0;
	cout << iGameCount << "회" << endl;
	cout << "Player2 차례! 1 ~ 9 사이의 숫자 중 숫자 3개를 입력하세요 (0 : 종료) : ";
	cin >> iInputNum[0] >> iInputNum[1] >> iInputNum[2];
	//종료 조건
	if (iInputNum[0] == 0 || iInputNum[1] == 0 || iInputNum[2] == 0)
		return;
	else if (iInputNum[0] < 0 || iInputNum[0] > 9
		|| iInputNum[1] < 0 || iInputNum[1] > 9
		|| iInputNum[2] < 0 || iInputNum[2] > 9) {
		cout << "잘못된 숫자를 입력했습니다." << endl;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (iNumder[i] == iInputNum[i]) {
				if (i == j) {
					iStrike++;
				}
				else {
					iBall++;
				}
			}
		}
	}
	iGameCount++;
	if (iStrike == 3) {
		cout << "Player2 정답!";
		return;
	}
	else {
		cout << iStrike << "Skrike" << " " << iBall << "Ball" << endl;
		
	}
}

int main() {
	// 배열에 숫자 값을 넣기
	// 1. 배열 세팅 완료
	// 1 ~ 9 까지의 숫자 설정하기
	for (int i = 0; i < 9; i++) {
		iNumder[i] = i + 1;
	}

	//2. 섞기
	srand((unsigned int)time(NULL));
	// 100번정도 섞어보기
	int idx1, idx2, temp;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9; // 0~8 //인덱스 번호이기 때문에 9가 아니라 8까지
		idx2 = rand() % 9;
		// cout << idx1 << " " << idx2 << endl;
		temp = iNumder[idx1];
		iNumder[idx1] = iNumder[idx2];
		iNumder[idx2] = temp;
	}
	cout << "* * *" << endl;
	cout << iNumder[0] << "\t" << iNumder[1] << "\t" << iNumder[2] << endl;

	while (true) {
		Player1();
		if (iStrike == 3) {
			break;
		}
		Player2();
		if (iStrike == 3) {
			break;
		}
	}
}

