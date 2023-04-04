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
	cout << "|    절대 음감 게임    |" << endl;
	cout << "-----------------------" << endl;
	cout << "설명 : 처음에 음계 8개를 들려주고 다음 8개 중 한 개 음을 들려준다" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "준비하고 아무키나 누른다" << endl;
	cout << "-----------------------" << endl;
	char ch = _getch();

	mm(523.25, " 도(1)");
	mm(587.33, " 레(2)");
	mm(659.26, " 미(3)");
	mm(698.46, " 파(4)");
	mm(783.99, " 솔(5)");
	mm(880, " 라(6)");
	mm(987.77, " 시(7)");
	mm(1046.50, " 도(8)\n");

	for (int i = 0; i < 3; i++)
	{
		cout << "\r" << 3 - i << "...";
		Sleep(1000);
	}
	Sleep(700);

	srand((unsigned int)time(NULL));
	while (true) {
		system("cls");
		cout << "!!!준비!!!" << endl;
		Sleep(500);
		int s = (rand() % 8) + 1;
		soundRd(s);
		char anser = _getch();
		if (((int)anser - '0') == s) {
			cout << "잘하셨습니다." << endl;
			cout << "게임을 그만둘까요? (Y/N)" << endl;
			ch = _getch();
			if (ch == 'y' || ch == 'Y') {
				break;
			}
		}
		cout << "틀리셨습니다." << endl;
		cout << "게임을 그만둘까요? (Y/N)" << endl;
		char ch = _getch();
		if (ch == 'y' || ch == 'Y') {
			break;
		}
	}
}