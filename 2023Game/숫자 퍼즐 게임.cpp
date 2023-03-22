#include <iostream>
#include <conio.h>

using namespace std;
void Init(int *_pNumber) {
	//����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
		_pNumber[i] = i + 1;
	_pNumber[24] = INT_MAX;
	//����
	int iTemp, idex1, idex2;
	for (int i = 0; i < 100; i++)
	{
		idex1 = rand() % 24;
		idex2 = rand() % 24;
		iTemp = _pNumber[idex1];
		_pNumber[idex1] = _pNumber[idex2];
		_pNumber[idex2] = iTemp;
	}
}
void RenderNumber(int* _pNumber) {
	cout << "====================" << endl;
	cout << "|   ���� ���� ����   |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "*�� �������� 1���� 24���� ������� �ǵ��� ������ ���� ������" << endl;
	cout << "==============================================================" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (5 * i + j == INT_MAX) {
				cout << "*" << endl;
			}
			else
				cout << _pNumber[i * 5 + j] << endl;
		}
	}
}
void Update(int* _pNumber) {
	
}
int main() {
	int iNumber[25] = {};
	Init(iNumber);
	while (true)
	{
		system("cls");
		RenderNumber(iNumber);
	}
}