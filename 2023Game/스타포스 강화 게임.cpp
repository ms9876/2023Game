#include <iostream>
using namespace std;

int main() {
	cout << "===================" << endl;
	cout << " 스타포스 강화 게임 " << endl;
	cout << "===================" << endl;

	srand((unsigned int)time(NULL));
	// 필요한 것 : 변수, 난수

	cout << "현재 무기는 몇성인가요? : ";
	int iUpgrade = 0;
	cin >> iUpgrade;
	float fPursent = rand() % 10001 / 100.f; // .f는 (float)해주는거랑 같음

	cout << "현재 무기 upgrade : " << iUpgrade << "성" << endl;
	cout << "강화 확률 persent : " << fPursent << endl;
	cout << "강화하시겠습니다? 예 : 1, 아니오 : 0  " << endl;

	int iInput;
	cin >> iInput;
	if (iInput == 0) // 이거 수행때 안 쓰면 감점
		return 0;

	if (iUpgrade <= 2) {
		if (fPursent <= 90.f)
			cout << "강화 성공!!!!" << endl;
		else
			cout << "강화 실패ㅜㅠㅠ" << endl;
	}
	else if (3 <= iUpgrade && iUpgrade <= 5) {
		if (fPursent <= 50.f)
			cout << "강화 성공!!!!" << endl;
		else
			cout << "강화 실패ㅜㅠㅠ" << endl;
	}
	else if (6 <= iUpgrade && iUpgrade <= 9) {
		if (fPursent <= 10.f)
			cout << "강화 성공!!!!" << endl;
		else
			cout << "강화 실패ㅜㅠㅠ" << endl;
	}
	else if (10 <= iUpgrade) {
		if (fPursent <= 1.f)
			cout << "강화 성공!!!!" << endl;
		else
			cout << "강화 실패ㅜㅠㅠ" << endl;
	}
}