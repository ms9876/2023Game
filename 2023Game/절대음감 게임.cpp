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
	cout << "|    ���� ���� ����    |" << endl;
	cout << "-----------------------" << endl;
	cout << "���� : ó���� ���� 8���� ����ְ� ���� 8�� �� �� �� ���� ����ش�" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "�غ��ϰ� �ƹ�Ű�� ������";

	// ���ļ�, ��(ms)

	while (true) {
		mm(523.25, " ��(1)");
		mm(587.33, " ��(2)");
		mm(659.26, " ��(3)");
		mm(698.46, " ��(4)");
		mm(783.99, " ��(5)");
		mm(880, " ��(6)");
		mm(987.77, " ��(7)");
		mm(1046.50, " ��(8)");

		break;
	}
}