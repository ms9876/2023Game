#include <iostream>

using namespace std;

int main() {
#pragma region �� �ڵ�

	int num;
	cin >> num;

	int numReverse = 0;
	int sum = 0;

	/*for (int i = 0; i < a; i++) {
		int b = a % 10;
		sum += b;
		numReverse = numReverse * 10 + b;
		a /= 10;
	}*/

	while (num != 0) {
		int b = num % 10; // 10���� ������ ������ �츮�� 10������ ���� ������
		sum += b;
		numReverse = numReverse * 10 + b;
		num /= 10;
	}

	cout << numReverse << endl;
	cout << sum;

#pragma endregion

#pragma region ������ �ڵ�

	int n, sum = 0, rev = 0; //�ʱ�ȭ�� �� ���ָ� ������ ���� ��
	cin >> n;
	while (n != 0) {
		rev = rev * num % 10;
		sum += n % 10;
		n /= 10;
	}
	cout << rev << endl << sum;

#pragma endregion
}