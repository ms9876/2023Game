#include <iostream>
#include <Windows.h>
#include <conio.h> // console input output

using namespace std;

int iNumber;
int iTime;

int main() {
	// getch() ���� �ִ� ���� �ٷ� �޾ƿ���, kbhit()// Ű���带 �����°�
	cout << "====================" << endl;
	cout << "|  �ð� ���߱� ����  |" << endl;
	cout << "====================" << endl;
	
	cout << "==============================================================" << endl;
	cout << "���� : �ð��� ��� �����Դϴ�." << endl;
	cout << "ó�� key�� ���߿� ���� key ������ �ð��� 10�ʷ� ����� ���ҽ��ϴ�." << endl;
	cout << "==============================================================" << endl;
	cout << "�ƹ�Ű�� ��������.";
	cout << "==============================================================" << endl;

	char ch = _getch();

	cout << "����!!";
	long startTime = time(NULL);
	cout << startTime << endl;

	while (true)
	{
		if (_kbhit()) {
			cout << "��~" << endl;
		}
		break;
	}

	if (time(NULL) - startTime == 10) {
		cout << "�����մϴ�. ����� ���߼̽��ϴ�" << endl;
	}
	else if (time(NULL) - startTime > 10) {
		cout << "�ð��� �������ϴ�" << endl;
	}
	else {
		cout << "���� ������ �ʾҽ��ϴ�" << endl;
	}
}