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
	cout << "      숫자 기억 게임입니다.     " << endl;
	cout << " EASY : 1, NORMAL : 2, HARD = 3 " << endl;
	cout << "===============================" << endl;
	srand((unsigned int)time(NULL));
}
void GameStart(MODE mode, int sleep) {
	// 동적할당 : new, delete
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
		cout << "EASY 모드입니다." << endl;
		break;
	case NORMAL:
		cout << "NORMAL 모드입니다." << endl;
		break;
	case HARD:
		cout << "HARD 모드입니다." << endl;
		break;
	}
	cout << "방금 본 숫자를 입력하세요!" << endl;
	for (int i = 0; i < mode * 5; i++) {
		cin >> iInput;
		if (iNumber[i] != iInput) {
			cout << "땡! 틀렸습니다";
			delete[] iNumber;
			return;
		}
	}
	cout << endl << "축하합니다, 다 맞았습니다";
	delete[] iNumber;
}
int main() {
	Init();

	int isSelectmaode;
	cin >> isSelectmaode;
	system("cls"); // 화면 지우기

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
		cout << "잘못 입력하셨습니다";
	}
}
