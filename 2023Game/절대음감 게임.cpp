#include <iostream>
#include <Windows.h>

using namespace std;

enum Scale {
	Do1,
	Re,
	Mi,
	Fah,
	So,
	La,
	Si,
	Do2
};

void mm(int i, string a) {
	cout << a << " ";
	Beep(i, 500);
}

int main() {

	cout << "-----------------------" << endl;
	cout << "|    절대 음감 게임    |" << endl;
	cout << "-----------------------" << endl;
	cout << "설명 : 처음에 음계 8개를 들려주고 다음 8개 중 한 개 음을 들려준다" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "준비하고 아무키나 누른다";

	// 주파수, 초(ms)

	while (true) {
		mm(523.25, " 도(1)");
		mm(587.33, " 레(2)");
		mm(659.26, " 미(3)");
		mm(698.46, " 파(4)");
		mm(783.99, " 솔(5)");
		mm(880, " 라(6)");
		mm(987.77, " 시(7)");
		mm(1046.50, " 도(8)");

		break;
	}
}