#include <iostream>
#include <Windows.h>
using namespace std;

enum MODE {
	EASY = 1,
	NORMAL,
	HARD
};
void Init() {
	cout << "===============================" << endl;
	cout << "      ���� ��� �����Դϴ�.     " << endl;
	cout << " EASY : 1, NORMAL : 2, HARD = 3 " << endl;
	cout << "===============================" << endl;
	srand((unsigned int)time(NULL));
}
void GameStart(MODE mode, int sleep) {
	// �����Ҵ� : new, delete
	int* iNumber = new int[mode * 5];
	int iInput;
	for (int i = 0; i < mode * 5; i++) {
		iNumber[i] = rand() % 100 + 1;
	}
	for (int i = 0; i < mode * 5; i++) {
		cout << iNumber[i] << " ";
		Sleep(sleep);
	}
	system("cls");
	switch (mode)
	{
	case EASY:
		cout << "EASY ����Դϴ�." << endl;
		break;
	case NORMAL:
		cout << "NORMAL ����Դϴ�." << endl;
		break;
	case HARD:
		cout << "HARD ����Դϴ�." << endl;
		break;
	}
	cout << "��� �� ���ڸ� �Է��ϼ���!" << endl;
	for (int i = 0; i < mode * 5; i++) {
		cin >> iInput;
		if (iNumber[i] != iInput) {
			cout << "��! Ʋ�Ƚ��ϴ�";
			delete[] iNumber;
			return;
		}
	}
	cout << endl << "�����մϴ�, �� �¾ҽ��ϴ�";
	delete[] iNumber;
}
int main() {
	Init();

	int isSelectmaode;
	cin >> isSelectmaode;
	system("cls"); // ȭ�� �����

	int* pNum;
	int num;
	int n = 0;
	switch (isSelectmaode)
	{
	case EASY:
		GameStart(EASY, 1000);
		break;
	case NORMAL:
		GameStart(NORMAL, 700);
		break;
	case HARD:
		GameStart(HARD, 500);
		break;
		break;
	default:
		cout << "�߸� �Է��ϼ̽��ϴ�";
	}
}
