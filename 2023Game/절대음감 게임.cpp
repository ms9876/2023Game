#include <iostream>
#include <Windows.h>
#include <conio.h> 

using namespace std;

void mm(int i, string a) {
	cout << a << " ";
	Beep(i, 800);
}
void soundRd(int s) {
	switch (s)
	{
	case 1: {
		Beep(523.25, 500);
	}
		  break;
	case 2: {
		Beep(587.33, 500);
	}
		  break;
	case 3: {
		Beep(659.26, 500);
	}
		  break;
	case 4: {
		Beep(698.46, 500);
	}
		  break;
	case 5: {
		Beep(783.99, 500);
	}
		  break;
	case 6: {
		Beep(880, 500);
	}
		  break;
	case 7: {
		Beep(987.77, 500);
	}
		  break;
	case 8: {
		Beep(1046.50, 500);
	}
		  break;
	default:
		cout << "...?";
		break;
	}
}

int main() {

	cout << "-----------------------" << endl;
	cout << "|    ���� ���� ����    |" << endl;
	cout << "-----------------------" << endl;
	cout << "���� : ó���� ���� 8���� ����ְ� ���� 8�� �� �� �� ���� ����ش�" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "�غ��ϰ� �ƹ�Ű�� ������" << endl;
	cout << "-----------------------" << endl;
	char ch = _getch();

	mm(523.25, " ��(1)");
	mm(587.33, " ��(2)");
	mm(659.26, " ��(3)");
	mm(698.46, " ��(4)");
	mm(783.99, " ��(5)");
	mm(880, " ��(6)");
	mm(987.77, " ��(7)");
	mm(1046.50, " ��(8)\n");

	for (int i = 0; i < 3; i++)
	{
		cout << "\r" << 3 - i << "...";
		Sleep(1000);
	}
	Sleep(700);

	srand((unsigned int)time(NULL));
	while (true) {
		system("cls");
		cout << "!!!�غ�!!!" << endl;
		Sleep(500);
		int s = (rand() % 8) + 1;
		soundRd(s);
		char anser = _getch();
		if (((int)anser - '0') == s) {
			cout << "���ϼ̽��ϴ�." << endl;
			cout << "������ �׸��ѱ��? (Y/N)" << endl;
			ch = _getch();
			if (ch == 'y' || ch == 'Y') {
				break;
			}
		}
		cout << "Ʋ���̽��ϴ�." << endl;
		cout << "������ �׸��ѱ��? (Y/N)" << endl;
		char ch = _getch();
		if (ch == 'y' || ch == 'Y') {
			break;
		}
	}
}