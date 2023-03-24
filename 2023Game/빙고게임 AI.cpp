#include <iostream>
#include <Windows.h> // sleep
using namespace std;
enum class AI_MODE {
	AM_EASY,
	AM_NORMAL
};
void Init(int* _pNumber)
{
	// ����
	//srand((unsigned int)time(NULL));
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
void RenderNumber(int* _pNumber, int& _iBingo)
{


	// ���ڸ� ���
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MAX)
				cout << "*" << "\t";
			else
				cout << _pNumber[i * 5 + j] << "\t";
		}
		cout << endl;
	}
	cout << "bingo Line : " << _iBingo << endl;
}
void ChangeNumber(int* _pNumber, int& _iBingo) {
	for (int i = 0; i < 25; i++) {
		if (_pNumber) {
			_pNumber[i] = INT_MAX;
		}
	}
}
int BingoCount(int* _pNumber) {
	int iCntBingo = 0;
	int iHorStar = 0, iVerStar = 0, iLTStar = 0, iRTStar = 0;

	for (int i = 0; i < 5; i++) {
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++) {
			if (_pNumber[i * 5 * j] == INT_MAX)
				iHorStar++;
			if (_pNumber[j * 5 * i] == INT_MAX)
				iVerStar++;

		}
		if (iHorStar == 5)
			iCntBingo++;
	}
	for (int i = 0; i < 25; i += 6) {
		if (_pNumber[i] == INT_MAX) {
			iLTStar++;
		}
	}
	if (iLTStar == 5)
		iCntBingo++;
	for (int i = 4; i < 20; i += 4) {
		if (_pNumber[i] == INT_MAX) {
			iRTStar++;
		}
	}
	if (iRTStar == 5)
		iCntBingo++;
	return iCntBingo;
}
AI_MODE SelcetAiMode() {
	cout << "====================" << endl;
	cout << "|     ���� ����     |" << endl;
	cout << "====================" << endl;

	cout << "==============================================================" << endl;
	cout << "            �������� 5�� �̻��̸� ���ӿ��� �¸��մϴ�!           " << endl;
	cout << "==============================================================" << endl;
	cout << "1. EASY" << endl;
	cout << "2. NORMAL" << endl;
	cout << "Ai ��带 �����ϼ���. " << endl;
	int iAimode;
	cin >> iAimode;
	// ���� ó��
	if (iAimode < static_cast<int>(AI_MODE::AM_EASY) || 
		iAimode > static_cast<int>(AI_MODE::AM_NORMAL)) {
		cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
	}
	return (AI_MODE)iAimode;
}
int SelcetAiNumber(int* _pNumber, AI_MODE _eMode) {

	int iNonSelect[25] = {};
	int iNonSelectCnt = 0;
	switch (_eMode)
	{
	case AI_MODE::AM_EASY: {
		for (int i = 0; i < 25; i++) {
			if(_pNumber[i] != INT_MAX){
				// ����
				iNonSelect[iNonSelectCnt] = _pNumber[i];
				++iNonSelectCnt;
			}
		}
		return iNonSelect[rand() % iNonSelectCnt];
	}
		break;
	case AI_MODE::AM_NORMAL: {

	}
		break;
	default:
		break;
	}
}
int main() {
	srand((unsigned int)time(NULL));
	int iNumber[25] = {};
	int iAiNumber[25] = {};
	int iBingo = 0, iAiBingo = 0;
	int iInput;
	Init(iNumber);
	Init(iAiNumber);
	while (true)
	{
		system("cls");
		cout << "==========================player========================" << endl;
		RenderNumber(iNumber, iBingo);
		cout << "============================AI==========================" << endl;
		AI_MODE eAimode = SelcetAiMode();
		switch (eAimode)
		{
		case AI_MODE::AM_EASY:
			cout << "AI MODE : EASY" << endl;
			break;
		case AI_MODE::AM_NORMAL:
			cout << "AI MODE : EASY" << endl;
			break;
		default:
			break;
		}
		RenderNumber(iAiNumber, iAiBingo);
		//�¸� ���� üũ
		if (iBingo >= 5) {
			cout << "���ӿ��� �¸��ϼ̽��ϴ�" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "AI�� ���ӿ��� �¸��Ͽ����ϴ�.";
		}
		//���� ����
		cout << "���ڸ� �Է��ϼ��� ( ���� : 0 ) : " << endl;
		cin >> iInput;

		if (iInput == 0) {
			cout << "������ �����մϴ�. " << endl;
		}
		else if (iInput < 1 || iInput > 25) {
			cout << "�߸� �Է��ϼ̽��ϴ�" << endl;
			continue;
		}
		ChangeNumber(iNumber, iBingo);
		ChangeNumber(iAiNumber, iAiBingo);
		//ai ��忡 ���� ai�� ������ ���ڸ� ������ ��
		iInput = SelcetAiNumber(iAiNumber, eAimode);
		cout << "AI�� ������ ���ڴ� " << iInput << "�Դϴ�" << endl;
		Sleep(1000);
		ChangeNumber(iNumber, iBingo);
		ChangeNumber(iAiNumber, iAiBingo);
		iBingo = BingoCount(iNumber);
		iAiBingo = BingoCount(iAiNumber);
	}

}