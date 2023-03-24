#include <iostream>
#include <Windows.h> // sleep
using namespace std;

void Init(int* _pNumber)
{
	// ����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
void RenderNumber(int* _pNumber, int& _iBingo)
{
	cout << "====================" << endl;
	cout << "|     ���� ����     |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "            �������� 5�� �̻��̸� ���ӿ��� �¸��մϴ�!           " << endl;
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
	cout << "bingo Line : " << _iBingo << endl;
}
void ChangeNumber(int* _pNumber, int& _iBingo) {
	for (int i = 0; i < 25; i++) {
		if (_pNumber) {
			_pNumber[i] = INT_MAX;
		}
	}
}
int BingoCount(int* _pNumber) {
	int iCntBingo = 0;
	int iHorStar = 0, iVerStar = 0, iLTStar = 0, iRTStar = 0;

	for (int i = 0; i < 5; i++) {
		iHorStar = iVerStar = 0; 
		for (int j = 0; j < 5; j++) {
			if (_pNumber[i * 5 * j] == INT_MAX) 
				iHorStar++;
			if (_pNumber[j * 5 * i] == INT_MAX)
				iVerStar++;
			
		}
		if (iHorStar == 5)
			iCntBingo++;
	}
	for (int i = 0; i < 25; i += 6) {
		if (_pNumber[i] == INT_MAX) {
			iLTStar++;
		}
	}
	if (iLTStar == 5)
		iCntBingo++;
	for (int i = 4; i < 20; i += 4) {
		if (_pNumber[i] == INT_MAX) {
			iRTStar++;
		}
	}
	if (iRTStar == 5)
		iCntBingo++;
	return iCntBingo;
}
int main() {
	int iNumber[25] = {};
	int iBingo = 0;
	int input;
	Init(iNumber);
	while (true)
	{
		system("cls");
		RenderNumber(iNumber, iBingo);
		if (iBingo >= 5) {
			cout << "���ӿ��� �¸��ϼ̽��ϴ�" << endl;
			break;
		}
		cout << "���ڸ� �Է��ϼ��� ( ���� : 0 ) : " << endl;
		cin >> input;

		if (input == 0) {
			cout << "������ �����մϴ�. " << endl;
		}
		else if (input < 1 || input > 25) {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		ChangeNumber(iNumber, iBingo);

		iBingo = BingoCount(iNumber);
		// �Էµ� �� �ٲٱ�
		for (int i = 0; i < 25; i++) {
			if (iNumber[i] == input) {
				iNumber[i] = -1;
				break;
			}
		}
		// ���� �Ǿ����� üũ�ϰ� ��������

		// ���� Ȯ���ϱ�
		for (int i = 0; i < 5; i++) {
			int h = 0, v = 0;
			for (int j = 0; j < 5; j++) {
				//����
				if (iNumber[(i * 5) + j] == -1)
					h++;
				//����
				if (iNumber[(j * 5) + i] == -1)
					v++;
			}
			if (h == 5) iBingo++;
			h = 0;
			if (v == 5) iBingo++;
			v = 0;
		}
		//�밢��
		int d = 0;
		for (int i = 0; i < 25; i += 6) {
			if (iNumber[i] == -1) {
				d++;
			}
		}
		if (d == 5) iBingo++;
		d = 0;
		for (int i = 4; i < 20; i += 4) {
			if (iNumber[i] == -1) {
				d++;
			}
		}
		if (d == 5) iBingo++;

		if (iBingo == 5) {
			cout << "************** ���� �ϼ� **************" << endl;
		}
	}
	
}