#include <iostream>
using namespace std;

int main() {
	cout << "===================" << endl;
	cout << " ��Ÿ���� ��ȭ ���� " << endl;
	cout << "===================" << endl;

	srand((unsigned int)time(NULL));
	// �ʿ��� �� : ����, ����

	cout << "���� ����� ��ΰ���? : ";
	int iUpgrade = 0;
	cin >> iUpgrade;
	float fPursent = rand() % 10001 / 100.f; // .f�� (float)���ִ°Ŷ� ����

	cout << "���� ���� upgrade : " << iUpgrade << "��" << endl;
	cout << "��ȭ Ȯ�� persent : " << fPursent << endl;
	cout << "��ȭ�Ͻðڽ��ϴ�? �� : 1, �ƴϿ� : 0  " << endl;

	int iInput;
	cin >> iInput;
	if (iInput == 0) // �̰� ���ට �� ���� ����
		return 0;

	if (iUpgrade <= 2) {
		if (fPursent <= 90.f)
			cout << "��ȭ ����!!!!" << endl;
		else
			cout << "��ȭ ���Ф̤Ф�" << endl;
	}
	else if (3 <= iUpgrade && iUpgrade <= 5) {
		if (fPursent <= 50.f)
			cout << "��ȭ ����!!!!" << endl;
		else
			cout << "��ȭ ���Ф̤Ф�" << endl;
	}
	else if (6 <= iUpgrade && iUpgrade <= 9) {
		if (fPursent <= 10.f)
			cout << "��ȭ ����!!!!" << endl;
		else
			cout << "��ȭ ���Ф̤Ф�" << endl;
	}
	else if (10 <= iUpgrade) {
		if (fPursent <= 1.f)
			cout << "��ȭ ����!!!!" << endl;
		else
			cout << "��ȭ ���Ф̤Ф�" << endl;
	}
}