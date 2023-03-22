#include <iostream>
#include <Windows.h>
#include <conio.h> // console input output

using namespace std;

int iNumber;
int iTime;

int main() {
	// getch() 여기 있는 값을 바로 받아오다, kbhit()// 키보드를 눌렀는가
	cout << "====================" << endl;
	cout << "|  시간 맞추기 게임  |" << endl;
	cout << "====================" << endl;
	
	cout << "==============================================================" << endl;
	cout << "설명 : 시간을 재는 게임입니다." << endl;
	cout << "처음 key와 나중에 누른 key 사이의 시간을 10초로 만들어 놓았습니다." << endl;
	cout << "==============================================================" << endl;
	cout << "아무키나 누르세요.";
	cout << "==============================================================" << endl;

	char ch = _getch();

	cout << "시작!!";
	long startTime = time(NULL);
	cout << startTime << endl;

	while (true)
	{
		if (_kbhit()) {
			cout << "끝~" << endl;
		}
		break;
	}

	if (time(NULL) - startTime == 10) {
		cout << "축하합니다. 당신은 맞추셨습니다" << endl;
	}
	else if (time(NULL) - startTime > 10) {
		cout << "시간이 지났습니다" << endl;
	}
	else {
		cout << "아직 지나지 않았습니다" << endl;
	}
}