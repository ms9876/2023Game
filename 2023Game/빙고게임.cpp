#include <iostream>
#include <Windows.h> // sleep
using namespace std;

void Init(int* _pNumber)
{
	// ����.
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;
	// �����.
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
		// �Էµ� �� �ٲٱ�
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
			if (v == 5) iBingo++;
		}

		if (iBingo == 5) {
			cout << "************** ���� �ϼ� **************" << endl;
			return 0;
		}
	}
}	