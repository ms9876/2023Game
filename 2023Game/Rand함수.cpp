#include <iostream>
#include <time.h>
using namespace std;

// rand를 활용한 문제가 무조건 수행에 나옴
int main() {
	int iNansu;

	srand((unsigned int)time(NULL)); //seed : 난수 테이블에 있는 첫번째 이름표
	for (int i = 0; i < 10; i++)
	{
		iNansu = rand() % 10 + 10;
		cout << iNansu << endl;
	}
}