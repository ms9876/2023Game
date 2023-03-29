#include<iostream>
#include<Windows.h> // sleep
using namespace std;

enum class AI_MODE
{
	AM_EASY = 1,
	AM_NORMAL
};
enum class LINE_NUMBER {
	LN_H1, LN_H2, LN_H3, LN_H4, LN_H5,
	LN_V1, LN_V2, LN_V3, LN_V4, LN_V5,
	LN_LT, LN_RT
};
void Init(int* _pNumber)
{
	// 셔플
	// 값 다 들어가있어.
	for (int i = 0; i < 25; i++)
		_pNumber[i] = i + 1;
	// 섞어요.
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; i++)
	{
		idx1 = rand() % 25; // 0 ~ 23
		idx2 = rand() % 25;
		iTemp = _pNumber[idx1];
		_pNumber[idx1] = _pNumber[idx2];
		_pNumber[idx2] = iTemp;
	}
}
// 값, 참조, 주소.
void RenderNumber(int* _pNumber, int& _iBingo)
{
	// 숫자를 출력해줄거야.
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
	cout << "Bingo Line: " << _iBingo << endl;
}
void ChangeNumber(int* _pNumber, int& _iInput)
{
	// 입력된 숫자와 현재 빙고판에서 일치하는지 확인을 하고,
	// INT_MAX
	for (int i = 0; i < 25; i++)
	{
		if (_pNumber[i] == _iInput)
			_pNumber[i] = INT_MAX;
	}
}
int BingoCount(int* _pNumber)
{
	int iCntBingo = 0;
	int iHorStar = 0, iVerStar = 0, iLTStar = 0, iRTStar = 0;
	// 가로, 세로, 대각선을 체크해줄겁니다.
	for (int i = 0; i < 5; i++)
	{
		iHorStar = iVerStar = 0;
		for (int j = 0; j < 5; j++)
		{
			if (_pNumber[i * 5 + j] == INT_MAX)
				iHorStar++;
			if (_pNumber[j * 5 + i] == INT_MAX)
				iVerStar++;
		}
		if (iHorStar == 5)
			iCntBingo++;
		if (iVerStar == 5)
			iCntBingo++;
	}

	// 대각선
	for (int i = 0; i < 25; i += 6)
	{
		if (_pNumber[i] == INT_MAX)
			iLTStar++;
	}
	if (iLTStar == 5)
		iCntBingo++;
	for (int i = 4; i <= 20; i += 4)
	{
		if (_pNumber[i] == INT_MAX)
			iRTStar++;
	}
	if (iRTStar == 5)
		iCntBingo++;
	return iCntBingo;
}
AI_MODE SelectAimode()
{
	std::cout << "======================================" << endl;
	std::cout << " |\t 빙고 게임입니다.\t" << endl;
	std::cout << "======================================" << endl;
	std::cout << "빙고줄이 5줄 이상이면 게임에서 승리합니다." << endl;
	std::cout << "======================================" << endl;
	cout << "1. EASY " << endl; // 남은 것중에 랜덤
	cout << "2. NORMAL " << endl; // 현재 한 줄을 완성할 수 잇는 가능성이 가장 높은 줄 선택.
	// 3. hard: 
	// 1) 가운데 무조건 -> 양쪽 모서리 -> 대각선 -> 가장 높은줄.
	cout << "AI모드를 선택하세요: " << endl;
	int iAimode;
	cin >> iAimode;
	// C, C++, C/C++
	// 예외처리. static_cast: c++, (): c
	if (iAimode < static_cast<int>(AI_MODE::AM_EASY) ||
		iAimode >(int)AI_MODE::AM_NORMAL)
	{
		cout << "잘못 입력하셨습니다." << endl;

	}
	return (AI_MODE)iAimode;
}
int SelectAinumber(int* _pNumber, AI_MODE _eMode)
{
	int iNoneSelect[25] = {};
	int iNoneSelectcnt = 0;
	switch (_eMode)
	{
	case AI_MODE::AM_EASY:
	{
		for (int i = 0; i < 25; i++)
		{
			if (_pNumber[i] != INT_MAX) // 숫자다.
			{
				iNoneSelect[iNoneSelectcnt] = _pNumber[i];
				++iNoneSelectcnt;
			}
		}
		return iNoneSelect[rand() % iNoneSelectcnt];
	}
	break;
	case AI_MODE::AM_NORMAL:
	{
#pragma region 선생님 코드
		int iLine = 0;
		int iStarcnt = 0;
		int iSavecnt = 0;

		// 가로줄
		for (int i = 0; i < 5; i++) {
			iStarcnt = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_pNumber[i * 5 + j] = INT_MAX) {
					iStarcnt++;
				}
			}
			if (iStarcnt < 5 && iSavecnt < iStarcnt) { // 제일 많은 줄로 빙고 줄 바꾸기
				iLine = 1;
				iSavecnt = iStarcnt;
			}
		}
		// 세로줄
		for (int i = 0; i < 5; i++) {
			iStarcnt = 0;
			for (int j = 0; j < 5; j++)
			{
				if (_pNumber[j * 5 + i] = INT_MAX) {
					iStarcnt++;
				}
			}
			if (iStarcnt < 5 && iSavecnt < iStarcnt) { // 제일 많은 줄로 빙고 줄 바꾸기
				iLine = i + 5;
				iSavecnt = iStarcnt;
			}
		}
		// LT 대각선
		iStarcnt = 0;
		for (int i = 0; i < 25; i+=6)
		{
			if (_pNumber[i] = INT_MAX) {
				iStarcnt++;
			}
		}
		if (iStarcnt < 5 && iSavecnt < iStarcnt) { // 제일 많은 줄로 빙고 줄 바꾸기
			iLine = (int)LINE_NUMBER::LN_LT;
			iSavecnt = iStarcnt;
		}
		// RT 대각선
		iStarcnt = 0;
		for (int i = 4; i < 20; i += 44)
		{
			if (_pNumber[i] = INT_MAX) {
				iStarcnt++;
			}
		}
		if (iStarcnt < 5 && iSavecnt < iStarcnt) { // 제일 많은 줄로 빙고 줄 바꾸기
			iLine = (int)LINE_NUMBER::LN_LT;
			iSavecnt = iStarcnt;
		}
		// 줄을 알게 되엇당! 야호오
		if (iLine <= (int)LINE_NUMBER::LN_H5) { // 가로
			for (int i = 0; i < 5; i++)
			{
				if (_pNumber[iLine * 5 + i] != INT_MAX)
					return _pNumber[iLine * 5 + i];
			}
		}
		else if (iLine <= (int)LINE_NUMBER::LN_V5) { // 세로
			for (int i = 0; i < 5; i++)
			{
				if (_pNumber[i * 5 + (iLine - 5)] != INT_MAX)
					return _pNumber[i * 5 + (iLine - 5)];
			}
		}
		else if (iLine <= (int)LINE_NUMBER::LN_V5) { // LT 대각선
			for (int i = 0; i < 25; i+=6)
			{
				if (_pNumber[i] != INT_MAX)
					return _pNumber[i];
			}
		}
		else if (iLine <= (int)LINE_NUMBER::LN_V5) { // RT 대각선
			for (int i = 4; i < 20; i += 4)
			{
				if (_pNumber[i] != INT_MAX)
					return _pNumber[i];
			}
		}
		return -1;
#pragma endregion


#pragma region 내 생각
		//int aihorstar = 0, aiverstar = 0, ailtstar = 0, airtstar = 0;

		//for (int i = 0; i < 5; i++)
		//{
		//	aihorstar = aiverstar = 0;
		//	for (int j = 0; j < 5; j++)
		//	{
		//		if (_pnumber[i * 5 + j] == int_max)
		//			aihorstar++;
		//		if (_pnumber[j * 5 + i] == int_max)
		//			aiverstar++;
		//	}
		//}

		//// 대각선
		//for (int i = 0; i < 25; i += 6)
		//{
		//	if (_pnumber[i] == int_max)
		//		ailtstar++;
		//}
		//if (ailtstar == 5)
		//	for (int i = 4; i <= 20; i += 4)
		//	{
		//		if (_pnumber[i] == int_max)
		//			airtstar++;
		//	}
		//// 모르겠어서 하드 코딩 했어욤..ㅎㅎ
		//if (aihorstar > aiverstar && aihorstar > ailtstar && aihorstar > airtstar) {
		//	for (int i = 0; i < 5; i++)
		//	{
		//		for (int j = 0; j < 5; j++)
		//		{
		//			if (_pnumber[i * 5 + j] == int_max)
		//				inoneselect[inoneselectcnt] = _pnumber[i];
		//		}
		//	}
		//	return inoneselect[rand() % inoneselectcnt];
		//}
		//if (aiverstar > aihorstar && aiverstar > ailtstar && aiverstar > airtstar) {
		//	for (int i = 0; i < 5; i++)
		//	{
		//		for (int j = 0; j < 5; j++)
		//		{
		//			if (_pnumber[j * 5 + i] == int_max)
		//				inoneselect[inoneselectcnt] = _pnumber[i];
		//		}
		//	}
		//	return inoneselect[rand() % inoneselectcnt];
		//}
		//if (ailtstar > aihorstar && ailtstar > aiverstar && ailtstar > airtstar) {
		//	for (int i = 0; i < 25; i += 6)
		//	{
		//		if (_pnumber[i] == int_max)
		//			inoneselect[inoneselectcnt] = _pnumber[i];
		//	}
		//	return inoneselect[rand() % inoneselectcnt];
		//}
		//if (airtstar > aihorstar && airtstar > ailtstar && airtstar > aiverstar) {
		//	for (int i = 4; i <= 20; i += 4)
		//	{
		//		if (_pnumber[i] == int_max)
		//			inoneselect[inoneselectcnt] = _pnumber[i];
		//	}
		//	return inoneselect[rand() % inoneselectcnt];
		//}
#pragma endregion
	}
	break;
	default:
		break;
	}
}
int main()
{
	srand((unsigned int)time(NULL));
	int iNumber[25] = {};
	int iAiNumber[25] = {};
	int iBingo = 0, iAiBingo = 0;
	int iInput;
	Init(iNumber);
	Init(iAiNumber);
	AI_MODE eAimode = SelectAimode();
	while (true)
	{
		system("cls");
		cout << "====================== Player =========================" << endl;
		RenderNumber(iNumber, iBingo);

		cout << "====================== AI ======================" << endl;
		switch (eAimode)
		{
		case AI_MODE::AM_EASY:
			cout << "AIMode: Easy" << endl;
			break;
		case AI_MODE::AM_NORMAL:
			cout << "AIMode: Normal" << endl;
			break;
		default:
			break;
		}
		RenderNumber(iAiNumber, iAiBingo);

		// 승리 조건 체크
		if (iBingo >= 5)
		{
			cout << "Player님이 게임에서 승리하셨습니다." << endl;
			break;
		}
		else if (iAiBingo >= 5)
		{
			cout << "AI가 게임에서 승리하셨습니다." << endl;
		}

		// 숫자 입력
		cout << "숫자를 입력하세요(0: 종료): " << endl;
		cin >> iInput;
		if (iInput == 0)
		{
			cout << "게임을 종료합니다." << endl;
			break;
		}
		else if (iInput < 1 || iInput > 25)
		{
			cout << "잘못 입력했습니다." << endl;
			continue;
		}
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);
		iInput = SelectAinumber(iAiNumber, eAimode);
		cout << "AI가 선택한 숫자는 " << iInput << "입니다." << endl;
		Sleep(1000);
		ChangeNumber(iNumber, iInput);
		ChangeNumber(iAiNumber, iInput);

		iBingo = BingoCount(iNumber);
		iAiBingo = BingoCount(iAiNumber);

	}
}