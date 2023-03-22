#include <iostream>
#include <conio.h>

using namespace std;

void Init(int* _pNumber)
{
	// ����.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
		_pNumber[i] = i + 1;
	_pNumber[24] = INT_MAX;
	// �����.
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
	cout << "|   ���� ���� ����   |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "  *�� �������� 1���� 24���� ������� �ǵ��� ������ ���� ������!   " << endl;
	cout << "==============================================================" << endl;

	// ���ڸ� ���
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
	cout << "W : ��, S : �Ʒ�, a : ����, d : ������, q : ����";
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
	// ���� üũ�ؼ� -> �迭�� ������� �Ǿ������� ��
	bool bchk = true;
	for (int i = 0; i < 24; i++) {
		if (_pNumber[i] != i + 1) {
			bchk = false;
			break;
		}
	}
	if (bchk == true) {
		cout << "�� �����!!!" << endl;
		return;
	}
}
int main()
{
	// �迭(1���� �迭)- ���þ˰���
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