#include <iostream>
using  namespace std;
// shuffle �˰��� 

int iStrike = 0;
int iBall = 0;
int iGameCount = 1;
int iInputNum[3];
int iNumder[9] = {};

void Player1() {
	iStrike = 0;
	iBall = 0;
	cout << iGameCount << "ȸ" << endl;
	cout << "Player1 ����! 1 ~ 9 ������ ���� �� ���� 3���� �Է��ϼ��� (0 : ����) : ";
	cin >> iInputNum[0] >> iInputNum[1] >> iInputNum[2];
	//���� ����
	if (iInputNum[0] == 0 || iInputNum[1] == 0 || iInputNum[2] == 0)
		return;
	else if (iInputNum[0] < 0 || iInputNum[0] > 9
		|| iInputNum[1] < 0 || iInputNum[1] > 9
		|| iInputNum[2] < 0 || iInputNum[2] > 9) {
		cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << endl;
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
		cout << "Player1 ����!";
		return;
	}
	else {
		cout << iStrike << "Skrike" << " " << iBall << "Ball" << endl;
	}
}

void Player2() {
	iStrike = 0;
	iBall = 0;
	cout << iGameCount << "ȸ" << endl;
	cout << "Player2 ����! 1 ~ 9 ������ ���� �� ���� 3���� �Է��ϼ��� (0 : ����) : ";
	cin >> iInputNum[0] >> iInputNum[1] >> iInputNum[2];
	//���� ����
	if (iInputNum[0] == 0 || iInputNum[1] == 0 || iInputNum[2] == 0)
		return;
	else if (iInputNum[0] < 0 || iInputNum[0] > 9
		|| iInputNum[1] < 0 || iInputNum[1] > 9
		|| iInputNum[2] < 0 || iInputNum[2] > 9) {
		cout << "�߸��� ���ڸ� �Է��߽��ϴ�." << endl;
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
		cout << "Player2 ����!";
		return;
	}
	else {
		cout << iStrike << "Skrike" << " " << iBall << "Ball" << endl;
		
	}
}

int main() {
	// �迭�� ���� ���� �ֱ�
	// 1. �迭 ���� �Ϸ�
	// 1 ~ 9 ������ ���� �����ϱ�
	for (int i = 0; i < 9; i++) {
		iNumder[i] = i + 1;
	}

	//2. ����
	srand((unsigned int)time(NULL));
	// 100������ �����
	int idx1, idx2, temp;
	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9; // 0~8 //�ε��� ��ȣ�̱� ������ 9�� �ƴ϶� 8����
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

