#include <iostream>
using namespace std;

int main() {
	cout << "===================" << endl;
	cout << " 什展匂什 悪鉢 惟績 " << endl;
	cout << "===================" << endl;

	srand((unsigned int)time(NULL));
	// 琶推廃 依 : 痕呪, 貝呪

	cout << "薄仙 巷奄澗 護失昔亜推? : ";
	int iUpgrade = 0;
	cin >> iUpgrade;
	float fPursent = rand() % 10001 / 100.f; // .f澗 (float)背爽澗暗櫛 旭製

	cout << "薄仙 巷奄 upgrade : " << iUpgrade << "失" << endl;
	cout << "悪鉢 溌懸 persent : " << fPursent << endl;
	cout << "悪鉢馬獣畏柔艦陥? 森 : 1, 焼艦神 : 0  " << endl;

	int iInput;
	cin >> iInput;
	if (iInput == 0) // 戚暗 呪楳凶 照 床檎 姶繊
		return 0;

	if (iUpgrade <= 2) {
		if (fPursent <= 90.f)
			cout << "悪鉢 失因!!!!" << endl;
		else
			cout << "悪鉢 叔鳶ぬばば" << endl;
	}
	else if (3 <= iUpgrade && iUpgrade <= 5) {
		if (fPursent <= 50.f)
			cout << "悪鉢 失因!!!!" << endl;
		else
			cout << "悪鉢 叔鳶ぬばば" << endl;
	}
	else if (6 <= iUpgrade && iUpgrade <= 9) {
		if (fPursent <= 10.f)
			cout << "悪鉢 失因!!!!" << endl;
		else
			cout << "悪鉢 叔鳶ぬばば" << endl;
	}
	else if (10 <= iUpgrade) {
		if (fPursent <= 1.f)
			cout << "悪鉢 失因!!!!" << endl;
		else
			cout << "悪鉢 叔鳶ぬばば" << endl;
	}
}