#include <iostream>
#include <conio.h>

using namespace std;
void Init(int *_pNumber) {
	//셔플
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 24; i++)
		_pNumber[i] = i + 1;
	_pNumber[24] = INT_MAX;
	//섞기
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
	cout << "|   숫자 퍼즐 게임   |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "*를 움직여서 1부터 24까지 순서대로 되도록 퍼즐을 맞춰 보세요" << endl;
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