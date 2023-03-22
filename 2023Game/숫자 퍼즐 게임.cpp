#include <iostream>
#include <conio.h>

using namespace std;

void Init(int* _pNumber)
{
	// 셔플.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
		_pNumber[i] = i + 1;
	_pNumber[24] = INT_MAX;
	// 섞어요.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
void RenderNumber(int* _pNumber)
{
	cout << "====================" << endl;
	cout << "|   숫자 퍼즐 게임   |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "  *를 움직여서 1부터 24까지 순서대로 되도록 퍼즐을 맞춰 보세요!   " << endl;
	cout << "==============================================================" << endl;

	// 숫자를 출력
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else
				cout << _pNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
}
char Update(int* _pNumber)
{
	cout << "W : 위, S : 아래, a : 왼쪽, d : 오른쪽, q : 종료";
	static int iStartindex = 24;
	char cInput = _getch();
	switch (cInput) {
	case 'w':
	case 'W': {
		if (iStartindex > 4) {
			_pNumber[iStartindex] = _pNumber[iStartindex - 5];
			_pNumber[iStartindex - 5] = INT_MAX;
			iStartindex -= 5;
		}
	}
			break;
	case 's':
	case 'S': {
		if (iStartindex < 20) {
			_pNumber[iStartindex] = _pNumber[iStartindex + 5];
			_pNumber[iStartindex + 5] = INT_MAX;
			iStartindex += 5;
		}
	}
			break;
	case 'a':
	case 'A': {
		if (iStartindex % 5 != 0) {
			_pNumber[iStartindex] = _pNumber[iStartindex - 1];
			_pNumber[iStartindex - 1] = INT_MAX;
			iStartindex -= 1;
		}
	}
			break;
	case 'd':
	case 'D': {
		if (iStartindex % 5 != 4) {
			_pNumber[iStartindex] = _pNumber[iStartindex + 1];
			_pNumber[iStartindex + 1] = INT_MAX;
			iStartindex += 1;
		}
	}
			break;
	default:
		break;
	}
	return cInput;
}
void PuzzleClear(int* _pNumber) {
	// 퍼즐 체크해서 -> 배열이 순서대로 되어있으면 끝
	bool bchk = true;
	for (int i = 0; i < 24; i++) {
		if (_pNumber[i] != i + 1) {
			bchk = false;
			break;
		}
	}
	if (bchk == true) {
		cout << "다 맞췄다!!!" << endl;
		return;
	}
}
int main()
{
	// 배열(1차원 배열)- 셔플알고리즘
	int iNumber[25] = {};
	Init(iNumber);
	while (true)
	{
		system("cls");
		RenderNumber(iNumber);
		Update(iNumber);
		PuzzleClear(iNumber);
		char chk = Update(iNumber);
		if (chk == 'q') {
				break;
		}
	}
}