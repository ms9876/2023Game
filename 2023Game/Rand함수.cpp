#include <iostream>
#include <time.h>
using namespace std;

// rand�� Ȱ���� ������ ������ ���࿡ ����
int main() {
	int iNansu;

	srand((unsigned int)time(NULL)); //seed : ���� ���̺� �ִ� ù��° �̸�ǥ
	for (int i = 0; i < 10; i++)
	{
		iNansu = rand() % 10 + 10;
		cout << iNansu << endl;
	}
}